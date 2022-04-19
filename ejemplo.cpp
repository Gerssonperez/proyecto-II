#include <iostream>
#include <mysql.h>

using namespace std;
 
char serverdb[] = "localhost";
char userdb[] = "umg";
char passworddb[] = "Umg$2019";
char database[] = "umg";
 
int main() {
	MYSQL* connection;
	long clienteId;
	string clienteNombre;
	string correo;
	string telefono;
	string direccion;
	string sql;
	const char* query;
	int result;
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;
			cout << "Ingrese el nombre del cliente: ";
			getline(cin, clienteNombre);
			cout << "Ingrese el correo del cliente: ";
			getline(cin, correo);
			cout << "Ingrese el telefono del cliente: ";
			getline(cin, telefono);
			cout << "Ingrese la direccion del cliente: ";
			getline(cin, direccion);
			sql = "INSERT INTO cliente(cliente_nombre, correo, telefono, direccion) VALUES ('" + clienteNombre + "', '" + correo + "', '" + telefono + "', '" + direccion + "')";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Registro guardado";
			}
			else
			{
				cout << "No fue posible guardar el registro " << mysql_error(connection) << endl;
			}
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT * FROM cliente";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa" << endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] << "\t";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	return 0;
}


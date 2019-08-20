#include <iostream>
#include <ctime>
#include <sstream> // buffer en memoria que simula comportarse como un archivo, no obtiene ni extrae datos directamente, se requiere asignarlos a otra variable
#include <cstdlib> // librería que nos ayuda a convertir cadenas de texto(string) en enteros

using namespace std;

string Dia_Mes_actual()
{
	time_t t = time(NULL);
	tm* PunteroDia_Mes = localtime(&t);
	
	stringstream ss_month;
	ss_month << PunteroDia_Mes->tm_mon+1;
	
	string mes = ss_month.str();
	
	if (atoi(mes.c_str()) < 10)
	{
		mes = "0"+mes;
	}
	
	stringstream ss_day;
	ss_day << PunteroDia_Mes->tm_mday;
	string dia = ss_day.str();
	
	if (atoi(dia.c_str()) < 10)
	{
		dia = "0"+dia;
	}	
	
	string dia_mes_actual = dia+"/"+mes;
	
	return dia_mes_actual;
}

string Anio_actual()
{
	time_t t = time(NULL);
	tm* PunteroTiempo = localtime(&t);
	
	stringstream ss_year;
	ss_year << PunteroTiempo->tm_year+1900;
	
	string anio = ss_year.str();
	
	string anio_actual = anio;
	
	return anio_actual;
	
}

int main()
{
	bool festivo;
	string dias_festivos[7] = {"01/01/", "05/02", "21/03", "01/05", "16/09", "20/11", "25/12"};
	
	int limite = (sizeof(dias_festivos)/sizeof(dias_festivos[0]));
	
	int i = 0;
	
	do
	{
		
		if (Dia_Mes_actual() == dias_festivos[i])
		{
			festivo = true;
		}
		else
		{
			festivo = false;
		}
		
		i = i+1;
		
	}while((i < limite) && (festivo == false));
	
	if (festivo == true)
	{
		cout<<"Hoy "+Dia_Mes_actual()+"/"+Anio_actual()+" es festivo\n";
	}
	else
	{
		cout<<"Hoy "+Dia_Mes_actual()+"/"+Anio_actual()+" no es festivo\n";
	}
	
	return 0;	
}



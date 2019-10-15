#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#include "adc.h"
#include "gpio.h"
#include "i2c.h"
#include "serial.h"
#include "timer.h"
#include "util.h"

#include "DHT11.h"
#include "DHT_Settings.h"
#include "IO_Macros.h"



void main (void) {
	uart_init();
	/**while (1) {
			/* remove this once you've verified it works
			printf_P(PSTR("Hello there\n"));
			_delay_ms(1000);
		} **/

	double temperature;
	double humidity;
	uint8_t data;


	DHT_Setup();

	while (1) {
		//DHT_Read(&temperature, &humidity);

		//data = DHT_Read(&temperature, &humidity);
		printf("%d\n", (int)DHT_status);
		printf("%d\n", (int)DHT_Ok);
		printf("%d\n", (int)DHT_Error_Humidity);
		printf("%d\n", (int)DHT_Error_Temperature);
		printf("%d\n", (int)DHT_Error_Checksum);
		printf("%d\n", (int)DHT_Error_Timeout);




		switch(DHT_Read(&temperature, &humidity))
		{
			case (DHT_Ok):
				printf_P(PSTR("Temperature: "));
				printf("%lf\n", temperature);
				printf_P(PSTR("Humidity: "));
				printf("lf\n", humidity);
				//printf_P(PSTR("%d",temperature));

				printf_P(PSTR("Humidity: "));
				printf("%lf\n", humidity);
				break;
			case (DHT_Error_Checksum):
				printf("Error Checksum\n");
				break;
			case (DHT_Error_Timeout):
				printf("Error Timeout\n");
				break;
			case (DHT_Error_Temperature):
				printf("%lf error temperature", temperature);
				break;
			case (DHT_Error_Humidity):
				printf("%lf error humidity", humidity);
				break;
		}

			_delay_ms(1000);




	}



}

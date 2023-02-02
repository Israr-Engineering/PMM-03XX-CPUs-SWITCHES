/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_ZERO_
#define _VARIANT_ARDUINO_ZERO_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers ahamd
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (20u)
#define NUM_ANALOG_INPUTS    (9u)
#define NUM_ANALOG_OUTPUTS   (1u)
#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LEDs (not defined for PMM0620)
#define PIN_LED_13           (13u)
#define PIN_LED_RXL          (25u)
#define PIN_LED_TXL          (26u)
#define PIN_LED              PIN_LED_13
#define PIN_LED2             PIN_LED_RXL
#define PIN_LED3             PIN_LED_TXL
#define LED_BUILTIN          PIN_LED_13

/*
 * Digital pins for PMM0620
 */
//01. Digital inputs on screw terminal 
#define PMM_DO_01          (3u) //PA07 : Digital Input 01
#define PMM_DO_02          (6u) //PA10 : Digital Input 02
#define PMM_DO_03          (5u) //PA09 : Digital Input 03
#define PMM_DO_04          (4u) //PA08: Digital Input 04
#define PMM_DO_05          (20u) //PA17 : Digital Input 05
#define PMM_DO_06          (2u) //PA06 : Digital Input 06
#define PMM_DO_07          (1u) //PA05 : Digital Input 07
#define PMM_DO_08          (18u)//PA16 : Digital Input 08
#define PMM_DO_09          (14u) //PA14 : Digital Input 09
#define PMM_DO_10          (39u) //PA18 : Digital Input 10
#define PMM_DO_11          (37u) //PA19 : Digital Input 11
#define PMM_DO_12          (15u) //PA15 : Digital Input 12
#define PMM_DO_13          (8u) //PA13 : Digital Input 13
#define PMM_DO_14          (7u) //PA11 : Digital Input 14
#define PMM_DO_15          (23u) //PB09 : Digital Input 15
#define PMM_DO_16          (0u) //PA04 : Digital Input 16
//02. Dip switches 
#define PMM_DI_PROG        (22u) //PB08 : Digital Input for programming mode - near termination dip switch
#define PMM_DI_PROG01      (42u) //PA03 : Digital Input - general (front panel dip switch )
#define PMM_DI_PROG02      (14u) //PA02 : Digital Input - general (front panel dip switch)
//03. Internal signals
//03a. Ethernet controller
#define PMM_DO_ETH_RST     (16u) //PB09 : Digital output : Ethernet controller reset command
#define PMM_D1_ETH_INT     (17u) //PA04 : Digital Input : Ethernet controller interrupt 
#define PMM_DO_SCSn        (10u) //PA18 : Digital output : Ethernet controller chip select command  
//03b. Flash memory
#define PMM_DO_FLASH_EN     (2u) //PA14 : Digital output : Flash Enable command
#define PMM_DO_FLASH_CS     (13u)//PA17 : Digital output : Flash chip select command 
//03c. Serial RS485
#define PMM_DO_RDENA        (29u)//PA27 : Digital output : RS485 Direction control  
//03d. options 
#define PMM_DI_INT        (34u)//PA19 : Digital Input : General interrupt from RTC or Extension boards  
#define PMM_DI_LossOfPower        (12u)//PB03 : Digital Input :loos of power 





 //* Analog pins (not defined for PMM0620)
 
#define PIN_A0               (14ul)
#define PIN_A1               (15ul)
#define PIN_A2               (16ul)
#define PIN_A3               (17ul)
#define PIN_A4               (18ul)
#define PIN_A5               (19ul)
// Add For 0632
#define PIN_A6               (4ul)
#define PIN_A7               (3ul)
#define PIN_A8               (1ul)
#define PIN_A9               (0ul)


#define PIN_DAC0             (14ul)



static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;

static const uint8_t A6  = PIN_A6;
static const uint8_t A7  = PIN_A7;
static const uint8_t A8  = PIN_A8;
static const uint8_t A9  = PIN_A9;




static const uint8_t DO1= PMM_DI_01  ;
static const uint8_t DO2= PMM_DI_02  ;
static const uint8_t DO3= PMM_DI_03  ;
static const uint8_t DO4= PMM_DI_04  ;
static const uint8_t DO5= PMM_DI_05  ;
static const uint8_t DO6= PMM_DI_06  ;
static const uint8_t DO7= PMM_DI_07  ;
static const uint8_t DO8= PMM_DI_08  ;
static const uint8_t DO9= PMM_DI_09  ;
static const uint8_t DO10= PMM_DI_10  ;
static const uint8_t DO11= PMM_DI_11  ;
static const uint8_t DO12= PMM_DI_12  ;
static const uint8_t DO13= PMM_DI_13  ;
static const uint8_t DO14= PMM_DI_14  ;
static const uint8_t DO15= PMM_DI_15  ;
static const uint8_t DO16= PMM_DI_16  ;

static const uint8_t DAC0 = PIN_DAC0;
#define ADC_RESOLUTION		12

// Other pins
#define PIN_ATN              (38ul)
static const uint8_t ATN = PIN_ATN;

/*
 * Serial interfaces
 */
// Serial (EDBG)
#define PIN_SERIAL_RX       (31ul)
#define PIN_SERIAL_TX       (30ul)
#define PAD_SERIAL_TX       (UART_TX_PAD_2)
#define PAD_SERIAL_RX       (SERCOM_RX_PAD_3)

// Serial1 (not defined for PMM0620)

#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)
#define PAD_SERIAL1_TX       (UART_TX_PAD_2)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_3)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (22u)
#define PIN_SPI_MOSI         (23u)
#define PIN_SPI_SCK          (24u)
#define PERIPH_SPI           sercom4
#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_RX           SERCOM_RX_PAD_0

//static const uint8_t SS	  = PIN_A2 ;	// SERCOM4 last PAD is present on A2 but HW SS isn't used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (20u)
#define PIN_WIRE_SCL         (21u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (27ul)
#define PIN_USB_DM          (28ul)
#define PIN_USB_DP          (29ul)

/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 1

#define I2S_DEVICE          0
#define I2S_CLOCK_GENERATOR 3
#define PIN_I2S_SD          (9u)
#define PIN_I2S_SCK         (1u)
#define PIN_I2S_FS          (0u)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial;
extern Uart Serial1;
extern Uart Serial2;
extern Uart Serial3;

#endif

#ifdef __cplusplus
extern "C" {
#endif
unsigned int PINCOUNT_fn();
#ifdef __cplusplus
}
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_ARDUINO_ZERO_ */
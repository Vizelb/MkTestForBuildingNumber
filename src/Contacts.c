#include "../inc/Contacts.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#pragma pack(push, 1)
typedef struct Bits
{
    uint16_t
        //PORT:16;
        Port0:1,
        Port1:1,
        Port2:1,
        Port3:1,
        Port4:1,
        Port5:1,
        Port6:1,
        Port7:1,
        Port8:1,
        Port9:1,
        Port10:1,
        Port11:1,
        Port12:1,
        Port13:1,
        Port14:1,
        Port15:1;
} Bits;
#pragma pack(pop)

union bitsPort
{
    uint16_t value;
    struct Bits bit;
};

#pragma pack(push, 1)
typedef struct Port
{
    union bitsPort PortG;
    union bitsPort PortD;
    union bitsPort PortB;
    union bitsPort PortA;
    union bitsPort RandomNumber;
} Port;
#pragma pack(pop)

void initPin()
{
    int i;
    Port port;

    port.PortG.value = PORTG_VALUE;
    port.PortD.value = PORTD_VALUE;
    port.PortB.value = PORTB_VALUE;
    port.PortA.value = PORTA_VALUE;

    printf("\nNumber = %x", port.RandomNumber.value);
    PresvoenieNumber(&port);
    printf("\nNumber = %x", port.RandomNumber.value);
}

void PresvoenieNumber(Port *port)
{
    port->RandomNumber.bit.Port0 = port->PortG.bit.Port8;
    port->RandomNumber.bit.Port1 = port->PortG.bit.Port7;
    port->RandomNumber.bit.Port2 = port->PortG.bit.Port6;
    port->RandomNumber.bit.Port3 = port->PortG.bit.Port5;
    port->RandomNumber.bit.Port4 = port->PortD.bit.Port15;
    port->RandomNumber.bit.Port5 = port->PortD.bit.Port14;
    port->RandomNumber.bit.Port6 = port->PortD.bit.Port13;
    port->RandomNumber.bit.Port7 = port->PortD.bit.Port12;
    port->RandomNumber.bit.Port8 = port->PortD.bit.Port11;
    port->RandomNumber.bit.Port9 = port->PortD.bit.Port10;
    port->RandomNumber.bit.Port10 = port->PortD.bit.Port9;
    port->RandomNumber.bit.Port11 = port->PortB.bit.Port8;
    port->RandomNumber.bit.Port12 = port->PortB.bit.Port2;
    port->RandomNumber.bit.Port13 = port->PortB.bit.Port1;
    port->RandomNumber.bit.Port14 = port->PortB.bit.Port0;
    port->RandomNumber.bit.Port15 = port->PortA.bit.Port6;
}


    /*printf("\nNumber = %x", port.RandomNumber.value);
    port.RandomNumber.bit.Port0 = port.PortG.bit.Port8;
    port.RandomNumber.bit.Port1 = port.PortG.bit.Port7;
    port.RandomNumber.bit.Port2 = port.PortG.bit.Port6;
    port.RandomNumber.bit.Port3 = port.PortG.bit.Port5;
    port.RandomNumber.bit.Port4 = port.PortD.bit.Port15;
    port.RandomNumber.bit.Port5 = port.PortD.bit.Port14;
    port.RandomNumber.bit.Port6 = port.PortD.bit.Port13;
    port.RandomNumber.bit.Port7 = port.PortD.bit.Port12;
    port.RandomNumber.bit.Port8 = port.PortD.bit.Port11;
    port.RandomNumber.bit.Port9 = port.PortD.bit.Port10;
    port.RandomNumber.bit.Port10 = port.PortD.bit.Port9;
    port.RandomNumber.bit.Port11 = port.PortB.bit.Port8;
    port.RandomNumber.bit.Port12 = port.PortB.bit.Port2;
    port.RandomNumber.bit.Port13 = port.PortB.bit.Port1;
    port.RandomNumber.bit.Port14 = port.PortB.bit.Port0;
    port.RandomNumber.bit.Port15 = port.PortA.bit.Port6;
    */

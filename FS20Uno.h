#include "REVISION.h"

#define PROGRAM "FS20Uno"
#define VERSION "1.00"


/* ==========================================================================
 * Hardware definition (I/O Ports...)
 * Zeiten in ms müssen Vielfache von 10 sein
 * ========================================================================== */
#define MAX_MOTORS				8

// timer period in ms
#define TIMER_MS				10

// Relais Ansprechzeit in ms (Datenblatt 5 ms)
#define OPERATE_TIME			20

// Relais Rückfallzeit in ms (Datenblatt 4 ms))
#define RELEASE_TIME			20

// Motor Umschaltdelay in ms
#define MOTOR_SWITCHOVER		250

// Motor maximale Laufzeit in ms
// Fenster auf:  47s
// Fenster zu:   47s
// Jalousie auf: 15s
// Jalousie zu:  18s
//#define MOTOR_MAXRUNTIME		47000
#define MOTOR_MAXRUNTIME		10000

// SM8 IN Schaltzeit in ms (muss Vielfaches von 10 sein)
#define FS20_SM8_IN_RESPONSE	150

// Tasten Entprellzeit in ms
#define DEBOUNCE_TIME			20


typedef unsigned int  WORD;
typedef unsigned long DWORD;
typedef DWORD TIMER;

#if MAX_MOTORS<=4
	#define IOBITS_ZERO	0x00
	typedef byte IOBITS;
#elif MAX_MOTORS<=8
	#define IOBITS_ZERO	0x0000
	typedef unsigned int IOBITS;
#elif MAX_MOTORS<=16
	#define IOBITS_ZERO	0x00000000
	typedef unsigned long IOBITS;
#else
#assert Too many motor devices (MAX_MOTORS > 16)
#endif

#define IOBITS_CNT	(MAX_MOTORS * 2)

typedef char MOTOR_CTRL;

#if   MOTOR_MAXRUNTIME<=255
typedef byte MOTOR_TIMEOUT;
#elif MOTOR_MAXRUNTIME<=65535
typedef WORD MOTOR_TIMEOUT;
#else
typedef DWORD MOTOR_TIMEOUT;
#endif

/*
    Envelope.h  

    Declaration of the Envelope class.

    ---------------------------------------------------------------------------
 
    Copyright (C) 2016, Cornfield Electronics, Inc.
 
    This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 
    Unported License.
 
    To view a copy of this license, visit
    http://creativecommons.org/licenses/by-sa/3.0/
 
    Created by Bill Alessi & Mitch Altman.
 
   ---------------------------------------------------------------------------
*/

#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include "Control.h"
#include "Scroller.h"

class Envelope : public TControl, public Scroller
{
   public:

   double  level;                // current output level

   Envelope();

   boolean charEv( char );       // process a character event
   void    dynamics();           // update object dynamics
   boolean evHandler( obEvent ); // handle an onboard event
   boolean ready();              // returns trigger status
   void    setAttack( byte );    // set attack time
   void    setDecay( byte );     // set decay time
   void    setSustain( byte );   // set sustain level
   void    setRelease( byte );   // set release time

   #ifdef KEYBRD_MENUS
   char    menu( key );          // map key event to character 
   #endif

   #ifdef CONSOLE_OUTPUT
   const   char *prompt();       // return object's prompt string
   #endif

   protected:

   byte    attack;               // attack time
   byte    decay;                // decay time
   byte    sustain;              // sustain level
   byte    release;              // release time

   double  attStep;              // change in attack per dynamic update
   double  decStep;              // change in decay per dynamic update
   double  susLevel;             // sustain level
   double  relStep;              // change in release per dynamic update

   byte    phase;                // current phase of envelope
                                 // enumerated values for phase:

   static const byte attPhase = 4;  
   static const byte decPhase = 3;
   static const byte susPhase = 2;
   static const byte relPhase = 1;
   static const byte finPhase = 0;

   word    exptime( byte );      // expand time to # of dynamic updates

} ;



#endif   // ifndef ENVELOPE_H_INCLUDED
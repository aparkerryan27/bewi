# BEWI by Parker Ryan

THE CONCEPT:

Transforming the interaction with an everyday water-bong from quiet bubbling and delinquency to a musical experience, consisting of generative composition, string synthesis, and introducing bite-size chunks of key music theory concepts for aspiring musicians, stoned or otherwise.  
Using a wind sensor inside the neck of the bong and sliders and knobs along the outside, the player can live control a set of variables, including the base key and chord of the composition to be generated, as well as the tempo, reverb, and filtering. There is also a digital view that allows the user to further modify the type of chord being produced and the timing of the melody. 

INSPIRATION:

This device is heavily inspired by the rapidly growing class of Electronic Wind Instruments (EWIs) that already exist, and from a technical aspect follows pretty squarely in the footsteps of those devices save for the use of suction to create wind pressure instead of blowing out. There is a group called Slamjam that has designed a harp-bong combo called the Arpabong, and it looks really cool, although it doesn’t appear to have left the drawing board. The bong itself also already exists obviously as somewhat of an acoustic instrument, with a calming, cool, nostalgic bubbling sound built right in to the mechanics.
The radio baton and Max Matthews himself of course serve not only as inspiration for this instrument but also in my general passion for the intersection of music and technology, and for opening up the definition of a digital instrument and how simple they can be to create really great music for "non-musicians".


SPECIFICS:

- The primary filtering of output and the melody trigger is controlled by the pressure of breath pulling in on the top opening of the bong. 
- The slider along the neck controls which root out of the major scale to form a chord from within that key.
- Knob 1: reverb (0-255)
- Knob 2: tempo (50-150bpm)
- Knob 3: key (0-11 [C-B#] )
- Knob 4: currently unused due to lack of analog pins on the Uno (see v2)

BUILDING PROCESS

Software: 
- Arduino C++ code for potentiometer and wind sensor inputs with Serial output in a very basic list format
- Max patch that takes in serial data and channels variables towards the generative melody
- Max patch that creates a generative melody given a key, chord type, tempo, and timing sequence
- Max patch that creates synthesized string sounds with variable reverb and spread
- I struggled alot with the synthesis, something I'm really excited to dig further into as I bring the instrument into a more commercial fidelity. The main sound that is produced now is formed of an implementation of the Karplus-Strong algorithm. 

Hardware: 
- A glass water bong
- 1 slide potentiometer
- 4 knob potentiometers 
- 1 Arduino Uno R3 
- 1 Wind Sensor (https://moderndevice.com/products/wind-sensor)


DEMONSTRATION:

A video of short performance / smoke sesh can be seen below: 

[![BEWI performance](https://img.youtube.com/vi/27rXpFg2-94/0.jpg)](https://www.youtube.com/watch?v=27rXpFg2-94)


FUTURE STEPS (v2!!)
- add a contact mic or hydrophone to have active input from the bubbling to amplify and emphasize the inherent musicality of a stand-alone water bong.
- have a version of the software that just sends MIDI data right through to Reaper so that I can experiment with how it functions as an interface for existing VSTs
- add onboard DSP (processed with PureData) and speakers 
- switch the main microchip to and ESP32 board for a more compact size
- A case to hide all of the wires between the bong and a thin layer of plastic so the look is more cohesive
- An attached bowl holster so that the bong can be played with burning substances involved initially and then easily held aside to create more music without causing lung dmage


*This instrument was originally designed as part of the Digital Musical Instrument Design course taught by Bryan Pardo at Northwestern University. Future versions are in the works, and collaboration is strongly encouraged! Please feel free to reach out if you're interested (apr@u.northwestern.edu). 

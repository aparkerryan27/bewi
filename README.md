# bewi

THE CONCEPT
Transforming the interaction with an everyday water-bong from quiet bubbling and delinquency to a musical experience, consisting of generative composition, string synthesis, and introducing bite-size chunks of key music theory concepts for aspiring musicians, stoned or otherwise.  
Using a wind sensor inside the neck of the bong and sliders and knobs along the outside, the user can live control a set of variables, including the base key and chord of the composition to be generated, as well as the tempo, reverb, and filtering.

INSPIRATION
This device is heavily inspired by the rapidly growing class of Electronic Wind Instruments (EWIs) in general already exist, and from a technical aspect follows pretty squarely in the footsteps of those devices save for the use of suction to create wind pressure instead of blowing out. 

There is a company called Slamjam that has designed a harp-bong combo called the Arpabong, and it looks really cool, although it doesn’t appear to have left the drawing board.
The harmonica also exists, which is both a blow and suck instrument that is super compact and sounds very cool.
The bong itself also exists, and has a calming, cool, nostalgic bubbling sound built right in to the mechanics.
The radio baton and Max Matthews himself of course serve not only as inspiration for this instrument but in my general passion for the intersection of music and technology, and for opening up the definition of what a digital instrument is and how simple they can be to create really great music for non-musicians.


SPECIFICS
Envelope is controlled by the pressure of breath pulling in on the top opening of the bong. 

The slider along the neck controls which root out of the major scale to form a chord from within that key.

Knob 1: reverb (0-255)
Knob 2: tempo (50-150bpm)
Knob 3: key (0-11 [C-B#] )
right knob: distortion/echo

BUILDING PROCESS
Software:
- Arduino C++ code for sensor inputs with Serial output in MIDI format, already have this
partially written
- Max patch that takes in MIDI serial data and makes it produce a generate melody - I’ll be
adapting the arduino/midi patch I wrote for the previous assignment along with using a key
and chord selector + melody generator a few other students created in my last Max class.
- Max patch already written that takes in water bubbling sounds and uses some fun Fourier
math I found online to time stretch them into an ambient looping wash of low echoing sounds
that leaves room for intentional precision, measures every 30ms so plenty of data points
collected for a few seconds of breath)
- Water bong from home
-
- I struggled alot with the synthesis, something I'm really excited to dig further into as I bring the instrument into a more commercial fidelity. The main sound that is produced now is formed of an implementation of the Karplus-Strong algorithm. 




A video of short performance / smoke sesh can be seen below: 

[![BEWI performance](https://img.youtube.com/vi/IYnsfV5N2n8/0.jpg)](https://www.youtube.com/watch?v=IYnsfV5N2n8)


FUTURE STEPS (v2!!)
- add a contact mic or hydrophone to have active input from the bubbling to amplify and emphasize the inherent musicality of a stand-alone water bong.
- have a version of the software that just sends MIDI data right through to Reaper so that I can experiment with how it functions as an interface for existing VSTs


*This instrument was originally designed as part of the Digital Musical Instrument Design course taught by Bryan Pardo at Northwestern University. Future versions are in the works, and collaboration is strongly encouraged! Please feel free to reach out if you're interested. 

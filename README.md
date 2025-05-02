# mvcpilot
Refurbish surplus and low cost microcontroller driven conference badges as a simple controller.

A recently discoverd discord channel of makers primarily creating electronic badges for technologists has uncovered a unique surplus electronics opportunity.  Due to quantity buying requirements and unpredictable attendance many organizations are in possession of hundreds of badges in pristine condition with potential for reuse. Purchase prices for full lots have been reported to be 10-15 cents on the dollar as organizations often lack storage space and are interested in recoverying a portion of their initial investment.

## Limitations:
1. Modifications shall be limited to ATTiny MCUs since remote sites may be soloar powered.
2. IO must be able to be ***exposed via Dupont connector***, male or female acceptable
3. Writeable memory requirements must exceed 4K
4. At least two output and one input IO interface.

### Example Controller circuit

<pre>```
Pull-up & Switch 
      +3 V
       │
     R3 10 kΩ  
       │  
   ATTiny85 INPUT
       │  
     [SW]─── GND  


Motor & Valve drivers
                           +3 V                     +3 V
                              │                        │
                         [Motor1]                  [Motor2]
                              │                        │
                              │                        │
                              C                        C
 ATTiny85 OUTPUT ──R1 10 kΩ──>B Q1             Q2<──R2 10 kΩ──  ATTiny85 OUTPUT
                              E                        E
                              │                        │
                              GND                      GND
   
   ```</pre>

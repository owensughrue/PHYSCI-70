    // Thank you to this site for this code: https://nathanmelenbrink.github.io/ps70/06_input/mic/index.html
    // Thank you very much to Nathan Melenbrink
    // Also thank you so much to Gabby Perry for guiding me throughout the process of this project.
    
    const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
    unsigned int sample;

    void setup() 
    {
       Serial.begin(9600);
    }


    void loop() 
    {
       unsigned long startMillis= millis();  // Start of sample window
       unsigned int peakToPeak = 0;   // peak-to-peak level

       unsigned int signalMax = 0;
       unsigned int signalMin = 1024;

       // collect data for 50 mS
       while (millis() - startMillis < sampleWindow)
       {
          sample = analogRead(0);   //reading DC pin from pin A0
          if (sample < 1024)  // toss out spurious readings
          {
             if (sample > signalMax)
             {
                signalMax = sample;  // save just the max levels
             }
             else if (sample < signalMin)
             {
                signalMin = sample;  // save just the min levels
             }
          }
       }
       peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude

       Serial.println(peakToPeak);
    }


/*
  This Arduino/Tympan code was auto-generated using the Tympan Audio System Design Tool

  The Tympan team hopes that you have fun with your audio hacking!
*/

//Include files
#include <Tympan_Library.h>

//Define the sample rate and block size
const float sample_rate_Hz = 16000 ; //16000, 24000 or 44117.647f (or other frequencies in the table in AudioOutputI2S_F32)
const int audio_block_samples = 128;  //smaller blocks (try 16) has less latency but may break SD writing or USB audio.  Do not make bigger than 128
AudioSettings_F32   audio_settings(sample_rate_Hz, audio_block_samples);

//Create audio objects
TympanPins			tympPins(TYMPAN_REV_D);	//TYMPAN_REV_C or TYMPAN_REV_D
TympanBase			audioHardware(tympPins);

AudioInputI2S_F32        audioInI2S(audio_settings);

AudioFilterBiquad_F32    biquad_l0(audio_settings);
AudioFilterBiquad_F32    biquad_l1(audio_settings);
AudioFilterBiquad_F32    biquad_l2(audio_settings);
AudioFilterBiquad_F32    biquad_l3(audio_settings);
AudioFilterBiquad_F32    biquad_l4(audio_settings);
AudioFilterBiquad_F32    biquad_l5(audio_settings);
//AudioFilterBiquad_F32    biquad_l6(audio_settings);
//AudioFilterBiquad_F32    biquad_l7(audio_settings);

AudioFilterBiquad_F32    biquad_r0(audio_settings);
AudioFilterBiquad_F32    biquad_r1(audio_settings);
AudioFilterBiquad_F32    biquad_r2(audio_settings);
AudioFilterBiquad_F32    biquad_r3(audio_settings);
AudioFilterBiquad_F32    biquad_r4(audio_settings);
AudioFilterBiquad_F32    biquad_r5(audio_settings);
//AudioFilterBiquad_F32    biquad_r6(audio_settings);
//AudioFilterBiquad_F32    biquad_r7(audio_settings);

AudioEffectCompressor_F32 compressor_l0(audio_settings);
AudioEffectCompressor_F32 compressor_l1(audio_settings);
AudioEffectCompressor_F32 compressor_l2(audio_settings);
AudioEffectCompressor_F32 compressor_l3(audio_settings);
AudioEffectCompressor_F32 compressor_l4(audio_settings);
AudioEffectCompressor_F32 compressor_l5(audio_settings);
//AudioEffectCompressor_F32 compressor_l6(audio_settings);
//AudioEffectCompressor_F32 compressor_l7(audio_settings);

AudioEffectCompressor_F32 compressor_r0(audio_settings);
AudioEffectCompressor_F32 compressor_r1(audio_settings);
AudioEffectCompressor_F32 compressor_r2(audio_settings);
AudioEffectCompressor_F32 compressor_r3(audio_settings);
AudioEffectCompressor_F32 compressor_r4(audio_settings);
AudioEffectCompressor_F32 compressor_r5(audio_settings);
//AudioEffectCompressor_F32 compressor_r6(audio_settings);
//AudioEffectCompressor_F32 compressor_r7(audio_settings);


AudioMixer8_F32          mixer8_l(audio_settings);
AudioMixer8_F32          mixer8_r(audio_settings);

AudioEffectCompressor_F32 compressor_l(audio_settings);
AudioEffectCompressor_F32 compressor_r(audio_settings);

AudioOutputI2S_F32       audioOutI2S(audio_settings);

//Create audio connections
AudioConnection_F32      patchCord00(audioInI2S, 0, biquad_l0, 0);
AudioConnection_F32      patchCord01(audioInI2S, 0, biquad_l1, 0);
AudioConnection_F32      patchCord02(audioInI2S, 0, biquad_l2, 0);
AudioConnection_F32      patchCord03(audioInI2S, 0, biquad_l3, 0);
AudioConnection_F32      patchCord04(audioInI2S, 0, biquad_l4, 0);
AudioConnection_F32      patchCord05(audioInI2S, 0, biquad_l5, 0);
//AudioConnection_F32      patchCord07(audioInI2S, 0, biquad_l6, 0);
//AudioConnection_F32      patchCord08(audioInI2S, 0, biquad_l7, 0);

AudioConnection_F32      patchCord09(audioInI2S, 1, biquad_r0, 0);
AudioConnection_F32      patchCord10(audioInI2S, 1, biquad_r1, 0);
AudioConnection_F32      patchCord11(audioInI2S, 1, biquad_r2, 0);
AudioConnection_F32      patchCord12(audioInI2S, 1, biquad_r3, 0);
AudioConnection_F32      patchCord13(audioInI2S, 1, biquad_r4, 0);
AudioConnection_F32      patchCord14(audioInI2S, 1, biquad_r5, 0);
//AudioConnection_F32      patchCord15(audioInI2S, 1, biquad_r6, 0);
//AudioConnection_F32      patchCord16(audioInI2S, 1, biquad_r7, 0);

AudioConnection_F32      patchCord17(biquad_l0, 0, compressor_l0, 0);
AudioConnection_F32      patchCord18(biquad_l1, 0, compressor_l1, 0);
AudioConnection_F32      patchCord19(biquad_l2, 0, compressor_l2, 0);
AudioConnection_F32      patchCord20(biquad_l3, 0, compressor_l3, 0);
AudioConnection_F32      patchCord21(biquad_l4, 0, compressor_l4, 0);
AudioConnection_F32      patchCord22(biquad_l5, 0, compressor_l5, 0);
//AudioConnection_F32      patchCord23(biquad_l6, 0, compressor_l6, 0);
//AudioConnection_F32      patchCord24(biquad_l7, 0, compressor_l7, 0);

AudioConnection_F32      patchCord25(biquad_r0, 0, compressor_r0, 0);
AudioConnection_F32      patchCord26(biquad_r1, 0, compressor_r1, 0);
AudioConnection_F32      patchCord27(biquad_r2, 0, compressor_r2, 0);
AudioConnection_F32      patchCord28(biquad_r3, 0, compressor_r3, 0);
AudioConnection_F32      patchCord29(biquad_r4, 0, compressor_r4, 0);
AudioConnection_F32      patchCord30(biquad_r5, 0, compressor_r5, 0);
//AudioConnection_F32      patchCord31(biquad_r6, 0, compressor_r6, 0);
//AudioConnection_F32      patchCord32(biquad_r7, 0, compressor_r7, 0);

AudioConnection_F32      patchCord33(compressor_l0, 0, mixer8_l, 0);
AudioConnection_F32      patchCord34(compressor_l1, 0, mixer8_l, 1);
AudioConnection_F32      patchCord35(compressor_l2, 0, mixer8_l, 2);
AudioConnection_F32      patchCord36(compressor_l3, 0, mixer8_l, 3);
AudioConnection_F32      patchCord37(compressor_l4, 0, mixer8_l, 4);
AudioConnection_F32      patchCord38(compressor_l5, 0, mixer8_l, 5);
//AudioConnection_F32      patchCord39(compressor_l6, 0, mixer8_l, 6);
//AudioConnection_F32      patchCord40(compressor_l7, 0, mixer8_l, 7);

AudioConnection_F32      patchCord41(compressor_r0, 0, mixer8_r, 0);
AudioConnection_F32      patchCord42(compressor_r1, 0, mixer8_r, 1);
AudioConnection_F32      patchCord43(compressor_r2, 0, mixer8_r, 2);
AudioConnection_F32      patchCord44(compressor_r3, 0, mixer8_r, 3);
AudioConnection_F32      patchCord45(compressor_r4, 0, mixer8_r, 4);
AudioConnection_F32      patchCord46(compressor_r5, 0, mixer8_r, 5);
//AudioConnection_F32      patchCord47(compressor_r6, 0, mixer8_r, 6);
//AudioConnection_F32      patchCord48(compressor_r7, 0, mixer8_r, 7);

AudioConnection_F32      patchCord49(mixer8_l, 0, compressor_l, 0);
AudioConnection_F32      patchCord50(mixer8_r, 0, compressor_r, 0);

AudioConnection_F32      patchCord51(compressor_l, 0, audioOutI2S, 0);
AudioConnection_F32      patchCord52(compressor_r, 0, audioOutI2S, 1);



//The setup function is called once when the system starts up
float32_t input_gain_dB = 15.0;  //this is a good starting point
float32_t vol_knob_gain_dB = 0.0; //this is a good starting point
void setup(void) {
	//Start the USB serial link (to enable debugging)
	Serial.begin(115200); delay(500);
	Serial.println("Setup starting...");

	//Allocate dynamically shuffled memory for the audio subsystem
	AudioMemory_F32_wSettings(20,audio_settings);  //allocate Float32 audio data blocks (primary memory used for audio processing)

	//Enable the Tympan to start the audio flowing!
	audioHardware.enable(); // activate AIC

	//Choose the desired input
	audioHardware.inputSelect(TYMPAN_INPUT_ON_BOARD_MIC);     // use the on board microphones
	//audioHardware.inputSelect(TYMPAN_INPUT_JACK_AS_MIC);    // use the microphone jack - defaults to mic bias 2.5V
	//audioHardware.inputSelect(TYMPAN_INPUT_JACK_AS_LINEIN); // use the microphone jack - defaults to mic bias OFF

	//Set the desired volume levels
	audioHardware.volume_dB(vol_knob_gain_dB);    // headphone amplifier.  -63.6 to +24 dB in 0.5dB steps.
	audioHardware.setInputGain_dB(input_gain_dB); // set input volume, 0-47.5dB in 0.5dB setps

	//service the potentiometer to get its current setting
	servicePotentiometer(millis(),0);

	//Put your own setup code here

  biquad_l0.setLowpass(0, 125, 1.414);
  biquad_r0.setLowpass(0, 125, 1.414);

  biquad_l1.setBandpass(0, 250, 1.414);
  biquad_r1.setBandpass(0, 250, 1.414);

  biquad_l2.setBandpass(0, 500, 1.414);
  biquad_r2.setBandpass(0, 500, 1.414);

  biquad_l3.setBandpass(0, 1000, 1.414);
  biquad_r3.setBandpass(0, 1000, 1.414);

  biquad_l4.setBandpass(0, 2000, 1.414);
  biquad_r4.setBandpass(0, 2000, 1.414);

  biquad_l5.setHighpass(0, 4000, 1.414);
  biquad_r5.setHighpass(0, 4000, 1.414);

  compressor_l0.setDefaultValues(sample_rate_Hz);
  compressor_l1.setDefaultValues(sample_rate_Hz);
  compressor_l2.setDefaultValues(sample_rate_Hz);
  compressor_l3.setDefaultValues(sample_rate_Hz);
  compressor_l4.setDefaultValues(sample_rate_Hz);
  compressor_l5.setDefaultValues(sample_rate_Hz);
//  compressor_l6.setDefaultValues(sample_rate_Hz);
//  compressor_l7.setDefaultValues(sample_rate_Hz);

  compressor_r0.setDefaultValues(sample_rate_Hz);
  compressor_r1.setDefaultValues(sample_rate_Hz);
  compressor_r2.setDefaultValues(sample_rate_Hz);
  compressor_r3.setDefaultValues(sample_rate_Hz);
  compressor_r4.setDefaultValues(sample_rate_Hz);
  compressor_r5.setDefaultValues(sample_rate_Hz);
//  compressor_r6.setDefaultValues(sample_rate_Hz);
//  compressor_r7.setDefaultValues(sample_rate_Hz);


  mixer8_l.setDefaultValues();
  mixer8_r.setDefaultValues();

  compressor_l.setDefaultValues(sample_rate_Hz);
  compressor_r.setDefaultValues(sample_rate_Hz);

	//End of setup
	Serial.println("Setup complete.");
};


//After setup(), the loop function loops forever.
//Note that the audio modules are called in the background.
//They do not need to be serviced by the loop() function.
void loop(void) {

	//periodically check the potentiometer
	servicePotentiometer(millis(),100); //update every 100 msec

	//check to see whether to print the CPU and Memory Usage
	printCPUandMemory(millis(),3000); //print every 3000 msec

};


// ///////////////// Servicing routines

//servicePotentiometer: listens to the blue potentiometer and sends the new pot value
//  to the audio processing algorithm as a control parameter
void servicePotentiometer(unsigned long curTime_millis, unsigned long updatePeriod_millis) {
	static unsigned long lastUpdate_millis = 0;
	static float prev_val = -1.0;

	//has enough time passed to update everything?
	if (curTime_millis < lastUpdate_millis) lastUpdate_millis = 0; //handle wrap-around of the clock
	if ((curTime_millis - lastUpdate_millis) > updatePeriod_millis) { //is it time to update the user interface?

		//read potentiometer (and quantize to reduce effects of noise)
		float val = float(audioHardware.readPotentiometer()) / 1023.0; //0.0 to 1.0
		val = (1.0/9.0) * (float)((int)(9.0 * val + 0.5)); //quantize so that it doesn't chatter...0 to 1.0

		//send the potentiometer value to your algorithm as a control parameter
		if (abs(val - prev_val) > 0.05) { //is it different than before?
			prev_val = val;  //save the value for comparison for the next time around

			//choose the desired gain value based on the knob setting
			const float min_gain_dB = -40.0, max_gain_dB = 20.0; //set desired gain range
			vol_knob_gain_dB = min_gain_dB + (max_gain_dB - min_gain_dB)*val; //computed desired gain value in dB
			audioHardware.volume_dB(vol_knob_gain_dB); //command the new volume setting
			Serial.print("servicePotentiometer: new volume dB = "); Serial.println(vol_knob_gain_dB); //print text to Serial port for debugging

			//Or, a better way to change volume is to change your algorithm gain, if you have such a block
			//const float min_gain_dB = -20.0, max_gain_dB = 40.0; //set desired gain range
			//vol_knob_gain_dB = min_gain_dB + (max_gain_dB - min_gain_dB)*val; //computed desired gain value in dB
			//gain1.setGain_dB(vol_knob_gain_dB); //command the new gain setting
			//Serial.print("servicePotentiometer: new volume dB = "); Serial.println(vol_knob_gain_dB); //print text to Serial port for debugging
		}
		lastUpdate_millis = curTime_millis;
	}; // end if
} //end servicePotentiometer();

//This routine prints the current and maximum CPU usage and the current usage of the AudioMemory that has been allocated
void printCPUandMemory(unsigned long curTime_millis, unsigned long updatePeriod_millis) {
	static unsigned long lastUpdate_millis = 0;
	//has enough time passed to update everything?
	if (curTime_millis < lastUpdate_millis) lastUpdate_millis = 0; //handle wrap-around of the clock
	if ((curTime_millis - lastUpdate_millis) > updatePeriod_millis) { //is it time to update the user interface?
		Serial.print("printCPUandMemory: ");
		Serial.print("CPU Cur/Peak: ");
		Serial.print(audio_settings.processorUsage());
		Serial.print("%/");
		Serial.print(audio_settings.processorUsageMax());
		Serial.print("%,   ");
		Serial.print("Dyn MEM Float32 Cur/Peak: ");
		Serial.print(AudioMemoryUsage_F32());
		Serial.print("/");
		Serial.print(AudioMemoryUsageMax_F32());
		Serial.println();

		lastUpdate_millis = curTime_millis; //we will use this value the next time around.
	};
};

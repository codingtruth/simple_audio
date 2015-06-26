#ifndef SIMPLE_AUDIO_H_INCLUDED
#define SIMPLE_AUDIO_H_INCLUDED

#define SIMPLE_AUDIO_OUTPUT_DEVICE_NAME		"output device name to be opened"
#define SIMPLE_AUDIO_OUTPUT_FREQUENCY		48000
#define SIMPLE_AUDIO_OUTPUT_DATA_WIDTH		24
#define SIMPLE_AUDIO_OUTPUT_BUFFER_SIZE		(64*1024)

#define SIMPLE_AUDIO_INPUT_DEVICE_NAME		"input device name to be opened"
#define SIMPLE_AUDIO_INPUT_FREQUENCY		48000
#define SIMPLE_AUDIO_INPUT_DATA_WIDTH		24
#define SIMPLE_AUDIO_INPUT_BUFFER_SIZE		(64*1024)

// Start Simple Audio Driver with the parameters specified in the macros in this file.
void simple_audio_start(void);

// Stop Simple Audio Driver.
void simple_audio_stop(void);

// This function is implemented by the user, and it must be called by the 
// Simple Audio Driver, when the new data is to be prepared by the user for the output.
// User should fill the data buffer within this call.
// Buffer size is always SIMPLE_AUDIO_OUTPUT_BUFFER_SIZE.
// Even if SIMPLE_AUDIO_OUTPUT_DATA_WIDTH is 8 bits, each data word is stored as uint32_t.
void simple_audio_output_request(uint32_t  *data_buffer);

// This function is implemented by the user, and it must be called by the 
// Simple Audio Driver, when the new data is received from the input.
// User should process the data from this data buffer within this call.
// Buffer size is always SIMPLE_AUDIO_INPUT_BUFFER_SIZE.
// Even if data width is 8 bits, each data word is stored as uint32_t.
void simple_audio_input_notify(uint32_t  *data_buffer);

#endif // SIMPLE_AUDIO_H_INCLUDED

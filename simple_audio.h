#ifndef SIMPLE_AUDIO_H_INCLUDED
#define SIMPLE_AUDIO_H_INCLUDED

// name of device which is used to open the ouput sound hardware in the operating system
#define SIMPLE_AUDIO_OUTPUT_DEVICE_NAME    "output device name to be opened"

// number of amplitudes in one second of output sound
#define SIMPLE_AUDIO_OUTPUT_FREQUENCY      48000

// number of bits in one amplitude for the output
#define SIMPLE_AUDIO_OUTPUT_DATA_WIDTH     24

// number of amplitudes passed to the Simple Audio Driver within single data request
#define SIMPLE_AUDIO_OUTPUT_BUFFER_LENGTH  (96 * 1024)

// number of bytes passed to the Simple Audio Driver within single data request
#define SIMPLE_AUDIO_OUTPUT_BUFFER_SIZE    (sizeof(uint32_t) * SIMPLE_AUDIO_OUTPUT_BUFFER_LENGTH)

// period of requesting output data from user by the Simple Audio Driver, measured in milliseconds
#define SIMPLE_AUDIO_OUTPUT_DATA_REQUEST_PERIOD \
          (1000 * SIMPLE_AUDIO_OUTPUT_BUFFER_SIZE / SIMPLE_AUDIO_OUTPUT_FREQUENCY)


// name of device which is used to open the input sound hardware in the operating system
#define SIMPLE_AUDIO_INPUT_DEVICE_NAME    "input device name to be opened"

// number of amnplitudes in one second of input sound
#define SIMPLE_AUDIO_INPUT_FREQUENCY       48000

// number of bits in one input amplitude
#define SIMPLE_AUDIO_INPUT_DATA_WIDTH      24

// number of amplitudes passed to user by the Simple Audio Driver within single data notification
#define SIMPLE_AUDIO_INPUT_BUFFER_LENGTH   (96*1024)

// number of bytes passed to user by the Simple Audio Driver within single data notification
#define SIMPLE_AUDIO_INPUT_BUFFER_SIZE    (sizeof(uint32_t) * SIMPLE_AUDIO_INPUT_BUFFER_LENGTH)


// Start the Simple Audio Driver with the parameters specified in the macro definitions in this file.
// After the Simple Audio Driver is started, it periodically calls the following two
// functions, provided by the user of the Simple Audio Driver:
//
//   * when data for the ouput is to be provided by the user, the Simple Audio Driver calls
//     simple_audio_output_request(uint32_t  *data_buffer),
//     and user should fill the output buffer with the amplitudes for the output.
//
//   * when the Simple Audio Driver has the amplitudes, received from the input device,
//     it calls the following function in order to pass the input amplitudes to the user:
//     simple_audio_input_notify(uint32_t  *data_buffer).
void simple_audio_start(bool start_output, bool start_input);


// Stop the Simple Audio Driver.
void simple_audio_stop(bool stop_output, bool stop_input);


// This function is implemented by the user, and it is periodically called by the 
// Simple Audio Driver, when the new amplitudes must be prepared by the user for the next output period.
// User should fill the anplitudes within this function.
// Buffer length is always SIMPLE_AUDIO_OUTPUT_BUFFER_LENGTH amplitudes, which is equal to
// SIMPLE_AUDIO_OUTPUT_BUFFER_SIZE bytes.
// Even if SIMPLE_AUDIO_OUTPUT_DATA_WIDTH is 8 bits, each amplitude is stored as uint32_t.
// Thus, this function is periodically called by the Simple Audio driver with the period, 
// calculated by this formula (measured in milliseconds): 
// SIMPLE_AUDIO_OUTPUT_REQUEST_CALL_PERIOD = 
//          (1000 * SIMPLE_AUDIO_OUTPUT_BUFFER_SIZE / SIMPLE_AUDIO_OUTPUT_FREQUENCY)
void simple_audio_output_data_request(uint32_t  *data_buffer);


// This function is implemented by the user, and it is periodically called by the 
// Simple Audio Driver, when the new data is received from the input sound hardware.
// User should process the data from this data buffer within this call.
// Buffer length is always SIMPLE_AUDIO_INPUT_BUFFER_LENGTH amplitudes, which is equal to
// SIMPLE_AUDIO_OUTPUT_BUFFER_SIZE bytes.
// Even if SIMPLE_AUDIO_INPUT_DATA_WIDTH is 8 bits, each amplitude is stored as uint32_t.
// Thus, this function is periodically called by the Simple Audio driver with the period, 
// calculated by this formula (measured in milliseconds): 
// SIMPLE_AUDIO_INPUT_REQUEST_CALL_PERIOD = 
//          (1000 * SIMPLE_AUDIO_INPUT_BUFFER_SIZE / SIMPLE_AUDIO_INPUT_FREQUENCY)
void simple_audio_input_data_notify(uint32_t  *data_buffer);


#endif // SIMPLE_AUDIO_H_INCLUDED

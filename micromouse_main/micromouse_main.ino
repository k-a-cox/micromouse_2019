/* Micromouse 2019 */

// Libraries
#include <DueTimer.h>

// Includes
#include "settings.h"
#include "encoder.h"
#include "sensor.h"

uint8_t sensor_addresses[SENSOR_COUNT] = { 0, 1, 2, 3, 4 }; // dummy values

void main_loop(){
  // Get sensor data
  static int8_t sensor_measurements[SENSOR_COUNT];
  readSensors(SENSOR_COUNT, sensor_addresses, sensor_measurements);
  
  // Get encoder data
  readEncoder(0); // Left encoder
  readEncoder(1); // Right encoder

  // Interpolate sensor and encoder data together using a kalman filter (measurement step)

  // Check if in a new cell
  // update map of the maze

  // if (at goal)
    // CheckStrategy(maze, location) to get new goal
  
  // determine what speed to set the motors to (speed profile)

  // Run predictions through the kalman filter (motion step)

  // Set speed using motor controller (pid loop)

}

void setup() {
  // Setup Sensors
  if (! sensorSetup(SENSOR_COUNT, sensor_addresses)){
    // Throw error? Serial message maybe?
  }
  
  // Setup Encoders
  encoderSetup(1, 2, 0); // pinA, pinB, id for left encoder
  encoderSetup(3, 4, 1); // pinA, pinB, id for right encoder
  
  Timer0.attachInterrupt(main_loop);
  Timer0.start(MAIN_LOOP_TIME);
}

void loop(){
  // do not use
}
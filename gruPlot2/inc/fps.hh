#pragma once
#include <iostream>
#include <chrono>

/**
 * @brief Checking duration between two measurements
 * 
 * ms - miliseconds between two measurements
 * fps - current Frames Per Second
 * showFps - determines if current FPS is displayed
 * 
 */
class Ftime
{
private:
  std::chrono::milliseconds last_time_ms;

public:
  // current delay between frames
  static double ms;
  // current fps
  static double fps;
  // show fps in stdout
  static bool showFps;

  /**
   * @brief Serring point of measure
   * 
   */
  void measure()
  {
    std::chrono::milliseconds now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    ms = (now_ms - last_time_ms).count();
    if (ms < 1)
      ms = 1;
    fps = 1000 / ms;
    if(showFps) std::cout << "FPS: " << fps <<std::endl;
    last_time_ms = now_ms;
  }
  /**
   * @brief Freezing program for SEC seconds
   * 
   * @param sec - seconds you want program to freeze
   */
  void wait(float sec)
  {
    std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    std::chrono::milliseconds t;
    do{
      t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    }while((t - now).count() <= sec*1000);
  }
};
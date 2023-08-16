// Program to calculate the ammount of time between two times

#include <stdio.h>
#include <stdbool.h>

// Define Structures
struct time {
int seconds;
int minutes;
int hours;
};

// Declare Functions
struct time getTime (void);
int convertToSeconds (struct time);
bool crossesZero (int, int);
int elapsedTime (int, int);
struct time convertToTime (int);
void printTime (struct time);

int main(void) {

  // Get input
  struct time first = getTime ();
  struct time last = getTime ();

  // Convert to seconds
  int firstInt = convertToSeconds (first);
  int secondInt = convertToSeconds (last);

  // Calculate the elapsed time
  int elapsed = elapsedTime (firstInt, secondInt);

  // Convert to time
  struct time elapsedTime = convertToTime (elapsed);

  // Print elapsed time
  printTime (elapsedTime);
  
  return 0;
}

// Define Functions
int convertToSeconds (struct time input) {
  int accumulator = 0;
  accumulator += input.seconds;
  accumulator += input.minutes * 60;
  accumulator += input.hours * 60 * 60;

  return accumulator;
}

struct time convertToTime (int input) {
  struct time output;
  
  output.seconds = input % 60;
  input /= 60;

  output.minutes = input % 60;
  input /= 60;

  output.hours = input;

  return output;
}

bool crossesZero (int start, int end) {
  if (start > end)
    return true;
  else 
    return false;
}

struct time getTime (void) {
  struct time input;
  printf ("Enter time (hh:mm:ss):  ");
  scanf ("%d:%d:%d", &input.hours, &input.minutes, &input.seconds);

  return input;
}

int elapsedTime (int start, int end) {
  int elapsed;
  const int timeInDay = 24 * 60 * 60;

  if (crossesZero (start, end)) {
    elapsed = timeInDay - end + start;
  }
  else {
    elapsed = end - start;
  }

  return elapsed;
}

void printTime (struct time input) {
  printf ("Time difference:        %.2d:%.2d:%.2d\n", input.hours, input.minutes, input.seconds);
}
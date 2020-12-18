# Thread-Win32

The program simulates simple multithreading application with “producer and consumer” problem

* The user can run the program and will enter two numbers on the command line. Those numbers will be used for buffer size and counter limit.
* The main program will then create two separate threads, producer and consumer thread.
* Producer thread generates a random number through random number generator function and inserts this into buffer and prints the number. Increment counter.
* Consumer thread goes to the buffer and takes a number in the proper order and prints it out. Increment counter.
* After counter reaches its limit, both threads terminate and return to main.
* Main program terminates.

# Skills
* C++
* Windows Win32

# Output Image
<img width="635" alt="Screen Shot 2020-12-18 at 6 31 14 PM" src="https://user-images.githubusercontent.com/34990882/102673023-88a34780-4160-11eb-97a0-665d236dcc47.png">

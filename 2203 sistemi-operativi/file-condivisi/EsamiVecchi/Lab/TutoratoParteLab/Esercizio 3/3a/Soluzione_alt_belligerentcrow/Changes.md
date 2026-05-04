CHANGES compared to timeassassinRG's code:
- It's all in english (personal preference and more used on the github platform)
- Less comments explaining the libraries and the parameters and the functions
- I use a thread to read the given file to count lines and words
  - Thus, I've used a thread_reading_resources struct to send everything to the thread from the main
  - A mutex was not needed as I start one single thread and I do not access the threadRes structure concurrently 
  - I start (create) and wait for (join) the thread before printing stats and exiting the program
- Slightly different way to count words and lines
- Different style of printing 
- Error handling library separated from main code
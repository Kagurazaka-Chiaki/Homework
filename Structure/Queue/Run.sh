gcc ListQueue.c -o ListQueue

valgrind -v --leak-check=full --track-origins=yes --log-file="QueueLog" ./ListQueue > Output
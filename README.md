# philosopher
the philosopher projects or a The Dining Philosophers problem is framed as follows: There are a certain number of philosophers sitting around a table, and there are an equal number of forks placed between them. Each philosopher needs two forks to eat their meal, one for the left hand and one for the right hand. The philosophers alternate between thinking and and sleeping and eating.
The problem arises when multiple philosophers attempt to pick up the forks simultaneously, leading to potential deadlock or resource starvation. For example, if every philosopher picks up their left fork simultaneously, they would all be waiting indefinitely for their right fork, resulting in a deadlock.
To solve the Dining Philosophers problem, wee can used, such as mutexes, semaphores, or other concurrency control mechanisms. These techniques ensure that the philosophers can access the forks in a coordinated and mutually exclusive manner, preventing deadlock.

--> same meaning of concept <----

In C programming language, a thread is a lightweight process that can run concurrently with other threads within the same process. Threads share the same memory and resources of the process, but they have their own stack, register set, and local variables.
* the processes can content multiple threads inside a single processes  but of cours you cannot have multiple processes in single thread
* with the thread all the variables in the same place so all threads can access to all variable and they all have a common set variable
* threads can sharing memories  so with threads all the file handlers share the file handlers but with processes all the file handlers are the duplicated

# 🐙 Pipex — 42 Yerevan project

**"Explore UNIX pipes by reimplementing shell behavior in C."**
A project to deepen your understanding of file descriptors, pipes, and process control in UNIX. Part of the School 42 curriculum.

---

## 📜 Description

Pipex re-creates the shell operation:

```
< file1 cmd1 | cmd2 > file2
```

Your program must parse four arguments and set up redirections and a pipe between two commands.

---

## 🚀 How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/Ashot877/So_long.git
   cd So_long/pipex
   ```

2. Compile the program:

   ```bash
   make
   ```

3. Execute with:

   ```bash
   ./pipex infile "cmd1 args" "cmd2 args" outfile
   ```

Example:

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
# Equivalent to: < infile ls -l | wc -l > outfile
```

---

## 📂 Project Structure

* `pipex.c`       — main entry point
* `utils.c/h`     — helper functions (error handling, memory)
* `exec.c/h`      — command execution and piping logic
* `Makefile`      — build rules

---

## 📜 Requirements

* Must be written in **C** following the Norm
* Must compile with flags: `-Wall -Wextra -Werror`
* Allowed functions: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`
* You may use your own `printf` implementation (`ft_printf`)
* No memory leaks; proper error handling

---

## 🧑‍💻 Author

* **Ashot Mkrtchyan**
  [42 Yerevan GitHub Profile](https://github.com/Ashot877)

---

## 📄 License

Project follows School 42 license. Handle all open-source code according to its original terms.

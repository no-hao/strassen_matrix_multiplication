# Strassen's algorithm

This project implements Strassen's algorithm for matrix multiplication and compares its performance to the<br>brute-force method. The program is written in C and determines the optimal crossover point for switching<br>between Strassen's algorithm and the brute-force method.

## File Structure

```
strassen-algorithm/
 └── bin/
    ├── matrix_app
    └── create_csv
 └── data/
    ├── matrix-1-pairs-of-2x2.csv
    └── matrix-3-pairs-of-8x8.csv
 └── include/
    ├── brute_force.h
    ├── create_csv.h
    ├── crossover.h
    ├── file_utils.h
    ├── matrix.h
    └── strassen.h
 └── output/
    ├── matrix-20-pairs-OUTPUT.csv
    ├── matrix-single-pair-OUTPUT.csv
    └── matrix-3-pairs-of-8x8-OUTPUT.csv
 ├── results/
 └── src/
    ├── brute_force.c
    ├── create_csv.c
    ├── crossover.c
    ├── file_utils.c
    ├── main.c
    ├── matrix.c
    └── strassen.c
 ├── Makefile
 └── README.md

```
### Folders

| Folder       | Description                                                            |
|--------------|------------------------------------------------------------------------|
| `bin`        | Contains the compiled binary executable of the program.                |
| `data`       | Stores the input files containing the matrices in CSV format.          |
| `include`    | Contains header files (`.h`) with function prototypes and necessary<br>type or constant definitions. |
| `output`     | Stores the output files generated by the program, such as the<br>resulting matrix after multiplication. |
| `results`    | Stores the results of the experiments, such as runtime analysis,<br>graphs, and spreadsheets. |
| `src`        | Contains the source code files (`.c`).                                  |

### src

This folder contains the following source code files:

| File          | Description                                                            |
|---------------|------------------------------------------------------------------------|
| `brute_force.c` | Implements the brute-force matrix multiplication algorithm.        |
| `create_csv.c` | Implements the functionality to generate CSV files with random<br>matrices for testing purposes. |
| `crossover.c`  | Implements the crossover algorithm that switches<br>between Strassen's and brute-force methods based on the given crossover point. |
| `file_utils.c`  | Contains the utility functions of the program shared over multiple source files.                |
| `main.c`      | Contains the main function to run the program and perform the experiments. |
| `matrix.c`    | Handles reading and writing matrices from/to CSV files,<br>and other matrix-related utilities. |
| `strassen.c`  | Implements Strassen's matrix multiplication algorithm.                |


### Generating Random Matrix CSV Files

The `create_csv` program allows you to generate random matrix CSV files for testing purposes.<br>To build and run the `create_csv` program, follow these steps:

1. Make sure you have a C compiler installed on your system (e.g., `gcc`).
2. Navigate to the project root directory (`strassen-algorithm`).
3. Run `make` to compile the project. The binary executable will be placed in the `bin` folder.
4. Run the `create_csv` program using the following command:

```bash
./bin/create_csv [n] [pairs]
```

To run the `create_csv` program, you will need to specify the following arguments:

`n`: the size of the matrix in the form of 2^n x 2^n<br>
`pairs`: the number of matrix pairs to generate<br>
The generated CSV file will be saved in the data folder with a<br>default naming convention: matrix-`[pairs]`-pairs-of-`[rows]`x`[cols]`.csv.

## Building and Running the Project

1. Make sure you have a C compiler installed on your system (e.g., `gcc`).
2. Navigate to the project root directory (`strassen-algorithm`).
3. Run `make` to compile the project. The binary executable will be placed in the `bin` folder.
4. Run the program using the following command:

```bash
./bin/matrix_app [input_file] [crossover_point] [-p]
```

To run the matrix_app program, you will need to specify the following arguments:

`input_file`: the path to the input file<br>
`crossover_point`: the crossover point for the genetic algorithm<br>
`-p`: an optional flag that can be used to print detailed results, including the matrices read from the input file,<br>output matrices, and elapsed times for each multiplication method (not best to set this for large values of n).

If you include the -p flag, the program will print detailed results, such as:

`-` The matrices read from the input file<br>
`-` The output matrices obtained using both the brute force and Strassen algorithms<br>
`-` The elapsed times for each pair of matrix multiplications<br>

This can be helpful for debugging and understanding the performance of the implemented algorithms.<br>If the -p flag is not provided, the program will only print the file paths where the output matrices are saved.

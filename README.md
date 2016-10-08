# linear-algebra-mth-204
I wrote this code to benchmark the performance of the cramer's rule against a simple decomposition method for solving linear systems of equations.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisities

What things you need to install the software and how to install them

```
1. nodejs (https://nodejs.org)
2. g++ compiler for C++
```

### Installing

A step by step series of examples that tell you have to get a development env running

**Linux**
```
Type these into your terminal
$ sh ./compile.sh
$ sh ./commands.sh

To solve a system of equations enter this (decomposition)
$ ./lu_eqn <filename.csv>

To solve a system of equations enter this (cramer's rule)
$ ./det_eqn <filename.csv>
```

**Windows**
```
Type these on your command line
> compile.bat
> commands.bat

To solve a system of equations enter this (decomposition)
> lu_eqn.exe <filename.csv>

To solve a system of equations enter this (cramer's rule)
> det_eqn.exe <filename.csv>
```

**Format of CSV file**
```
How the CSV file should be written so that the program can read it properly.

For an equation with two unknowns
A = | 2 4 |
    | 8 3 |

b = ( 3, 6 )
x = ( x, y )

The CSV file should look like this
2,4,3
8,3,6
```
**This CSV file should be n by (n + 1) or the program will throw an error**


## Built With

* Atom
* Nodejs

## Authors

* **Michael Ogezi**

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

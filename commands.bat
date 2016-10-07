echo OFF
echo THIS SCRIPT COMPARES THE PERFORMANCE OF THE DETERMINANT AND LU METHODS OF SOLVING A LINEAR SYSTEM

rem These commands create a matrix for an equation with 5 unknowns, then time the computation of the solution by the lu method and the determinant method for linear systems respectively
echo.
echo An equation with 5 unknowns
echo Generating matrix for equation with 5 unknowns
node gen_eqn.js 5
echo Generated matrix for equation with 5 unknowns
echo Started timing lu method for equation with 5 unknowns
powershell "Measure-Command {.\lu_eqn.exe}"
echo Done timing lu method for equation with 5 unknowns
echo Started timing determinant method for equation with 5 unknowns
powershell "Measure-Command {.\det_eqn.exe}"
echo Done timing determinant method for equation with 5 unknowns
pause

rem These commands create a matrix for an equation with 10 unknowns, then time the computation of the solution by the lu method and the determinant method for linear systems respectively
echo.
echo An equation with 10 unknowns
echo Generating matrix for equation with 10 unknowns
node gen_eqn.js 10
echo Generated matrix for equation with 10 unknowns
echo Started timing lu method for equation with 10 unknowns
powershell "Measure-Command {.\lu_eqn.exe}"
echo Done timing lu method for equation with 10 unknowns
echo Started timing determinant method for equation with 10 unknowns
powershell "Measure-Command {.\det_eqn.exe}"
echo Done timing determinant method for equation with 10 unknowns
pause

rem These commands create a matrix for an equation with 50 unknowns, then time the computation of the solution by the lu method and the determinant method for linear systems respectively
echo.
echo An equation with 50 unknowns
echo Generating matrix for equation with 50 unknowns
node gen_eqn.js 50
echo Generated matrix for equation with 50 unknowns
echo Started timing lu method for equation with 50 unknowns
powershell "Measure-Command {.\lu_eqn.exe}"
echo Done timing lu method for equation with 50 unknowns
echo Started timing determinant method for equation with 50 unknowns
powershell "Measure-Command {.\det_eqn.exe}"
echo Done timing determinant method for equation with 50 unknowns
pause

rem These commands create a matrix for an equation with 150 unknowns, then time the computation of the solution by the lu method and the determinant method for linear systems respectively
echo.
echo An equation with 150 unknowns
echo Generating matrix for equation with 150 unknowns
node gen_eqn.js 150
echo Generated matrix for equation with 150 unknowns
echo Started timing lu method for equation with 150 unknowns
powershell "Measure-Command {.\lu_eqn.exe}"
echo Done timing lu method for equation with 150 unknowns
echo Started timing determinant method for equation with 150 unknowns
powershell "Measure-Command {.\det_eqn.exe}"
echo Done timing determinant method for equation with 150 unknowns
pause

echo.
echo Solution for equation with 20 unknowns
echo Generating matrix for equation with 20 unknowns
node gen_eqn.js 20
echo Generated matrix for equation with 20 unknowns
.\lu_eqn.exe

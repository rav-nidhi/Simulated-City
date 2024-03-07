# SimCity Project 2 - README

## Group Members
- Nidhi Ravala
- Kolade Olojo
- Monique Simberg

## Introduction
This README provides instructions on how to compile and run our SimCity Project 2 Final program using PuTTY. This version requires compiling the following files: 'main.cpp', 'residential.h', 'industrial.h', 'commercial.h', 'pollution.h', 'functions.h', 'readwrite.h', 'zoom.h', 'residential.cpp', 'industrial.cpp', 'commercial.cpp', 'pollution.cpp', 'functions.cpp', 'readwrite.cpp', 'zoom.cpp'
- Sample configuration and region files can be found in the "Documentation" folder of this repository.
- Ensure all files are in the same directory.

## Prerequisites
Before you begin, ensure that you have the following:
- Access to PuTTY for SSH access to the server.

## Instructions

### 1. Connect to the Server using PuTTY
    - If you are connecting from outside the campus, make sure you use Cisco Anyconnect to connect to the campus vpn.
    - Open PuTTY.
    - In the "Host Name" field, enter the server address and port provided to you.
    - Select the SSH connection type.
    - Click "Open" to start the connection.
    - Log in with your credentials when prompted.

### 2. Upload Files to the Server
    - Use an SFTP client like WinSCP or the `pscp` command if you're on Windows to upload the files listed in the introduction to the server.
    - Place these files in a directory where you want to compile and run your program.

### 3. Compilation
    - Open the terminal in PuTTY.
    - Navigate to the directory where you uploaded the files using the `cd` command.
    - Compile the program using the command: 'g++ *.cpp'
        - Alternatively, you can use the command 'g++ main.cpp residential.cpp industrial.cpp commercial.cpp pollution.cpp functions.cpp readwrite.cpp', but this is not reccomended as it compiles the same as the above command, which is shorter.
    - If the file compiles correctly then you should see no message.
    - There should now be an a.out file.
    - Execute the a.out file using './a.out'

### 4. Running the Program
    - After the program executes, there should be a prompt that says: "Input name of configuration file:"
    - Enter the file name "config2.txt" and hit enter.
    - The initialized region map should be generated
    - All zones with 0 population should be printed out as an I, C, A, or H depending on which zone it is in.
    - The code will now print out the zones for all 40 timesteps, replacing the letters with numbers as the populations are updated.
        - During this process, the screen will clear between time steps, so the map will be "animated" as it updates
        - A log will be created to track previous time steps as well.
    - There will be an output with three different pollution outputs (air, light, sound), with air addressing the pollution functionality expected in project 1
    - You will have the option to traverse all time steps to get information about their pollution and population as well as focus on specific areas of the map. You will also be prompted to enter specific coordinates in the map to zoom into the map and print the specific area you want to see. To end the prompt for time step traversal, enter -1.
    - The program should automatically terminate after this.

## Troubleshooting
    - If you encounter any errors during compilation or execution, refer to the error messages in the terminal for more information.
    - Ensure that the uploaded files are ALL in the correct directory and spelled correctly.

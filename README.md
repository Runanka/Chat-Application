# ServerClientChatApplication

The ServerClientChatApplication is a server-client chat application that features a user-friendly graphical user interface (GUI) and is built using C++ and QT. It utilizes QTCPSocket and QTCPServer to implement the client and server functionalities, respectively. The application is designed to read and write from the socket descriptor.

## Installation Instructions

To install the application, please follow these steps:

1. Install the QT 5.12.12 framework.
2. Install Visual Studio with the QT Tools Extension.
3. Open the provided solution (.sln) file in Visual Studio for ease of access.

## File Description

The project consists of four classes and one custom widget:

1. `MainApplication` - this is the main class and is responsible for handling all program operations.
2. `Client` and `Server` classes - these classes are used to represent the client and server, respectively.
3. `ConnectDialog` class - this class is used to open up a dialog box and receive input for the IP address, port number, and whether the program is used as a server or a client.
4. `MyMessage` class - this is a custom QTextEdit widget that adds several functionalities to the UI and other properties.

The following image illustrates the flow control between the classes:

![Flow Control Diagram](https://i.imgur.com/azaT6zE.png "Flow Control Diagram")

## Screenshots

Below are some screenshots of the application:

1. Main application window - <br>
![Main Application Window Image](https://i.imgur.com/nR0bog9.png "Main Application Window Image")

2. Dialog window - <br>
![Dialog Window Image](https://i.imgur.com/DlrZO0o.png "Dialog Window Image")

3. Application in action: Chat of two sides - <br>
![Chat of Two Sides Image](https://i.imgur.com/aAxBqDo.png "Chat of Two Sides Image")

## Contribution

We welcome contributions to this project in the following ways:

1. Adding styles to the application.
2. Adding threads to it so that multiple chats can occur at the same time.

## Contact Information

If you have any questions or concerns about this project, please feel free to contact us at the following email address: `runanka@outlook.com`.

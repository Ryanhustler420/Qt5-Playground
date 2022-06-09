## How to deploy the qt quick application on window

- Create a new qt quick project
- Change to release build
- Change the "qml:/main.qml" -> "main.qml"
- Build the project
- Go to release folder, open cmd
- run `C:\Qt\Qt5.12.12\5.12.12\mingw73_64\bin\windeployqt --qmldir C:/YourProject/qmls C:/Build/release`
- Paste the **qmls and qrc** from `C:/YourProject/qmls` to `C:/Build/release`

## How to deploy the qt application on window

- Create a new QtWidget project
- Change to release build
- Build the project
- Go to release folder, open cmd
- run `C:\Qt\Qt5.12.12\5.12.12\mingw73_64\bin\windeployqt C:/Build/release`
- paste the .dlls from `C:\Qt\Qt5.12.12\5.12.12\mingw73_64\bin` to `C:/Build/release`

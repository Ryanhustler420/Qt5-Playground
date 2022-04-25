#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket socket;
    socket.connectToHost("gouravgupta.com", 80);

    qInfo() << "Connecting\u2026";
    if (socket.waitForConnected(60000)) // 1 Minute
    {
        qInfo() << "Connected sending request";

        QByteArray data;
        data.append("GET /get HTTP/1.1\r\n");
        data.append("Host: local\r\n");
        data.append("Connection: Close\r\n");
        data.append("\r\n");

        socket.write(data);
        socket.waitForBytesWritten(/* can write 60000*/);

        if (socket.waitForReadyRead(60000))
        {
            QByteArray response = socket.readAll();
            qInfo() << "Response: " << response.length() << " bytes";
            qInfo() << "Response: " << response;
        }

        // socket.close(); // we are asked the server to close the connection
        socket.waitForDisconnected();
        qInfo() << "Done!";

    }
    else
    {
        qInfo() << socket.errorString();
    }

    return a.exec();
}

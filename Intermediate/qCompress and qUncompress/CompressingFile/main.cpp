#include <QCoreApplication>
#include <QTextStream>
#include <QBuffer>
#include <QDebug>
#include <QFile>
#include <QDir>

// Our own custom file format, will not work with anything else:

bool makeFile(QString path) {
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        QByteArray data;
        for (int var = 0; var < 1000; ++var) {
            data.append(QString::number(var) + "\r\n");
        }
        file.write(data);
        file.close();
        return true;
    }
    return false;
}

QByteArray getHeader() {
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFile, QString newFile) {
    QFile ofile (originalFile), nfile(newFile);
    QByteArray header = getHeader();

    if (!ofile.open(QIODevice::ReadOnly)) return false;
    if (!nfile.open(QIODevice::WriteOnly)) return false;

    int size = 1024;

    while (!ofile.atEnd()) {
        QByteArray buffer = ofile.read(size);
        QByteArray compressed = qCompress(buffer);
        qInfo() << "Header at: " << nfile.pos();

        nfile.write(header);
        qInfo() << "Size: " << nfile.write(compressed); // unknown size
    }

    ofile.close();
    nfile.close();

    return true;
}

bool decompressFile(QString originalFile, QString newFile) {
    QFile ofile (originalFile), nfile(newFile);
    QByteArray header = getHeader();

    if (!ofile.open(QIODevice::ReadOnly)) return false;
    if (!nfile.open(QIODevice::WriteOnly)) return false;

    int size = 1024;

    // Double check that We compressed the file
    QByteArray buffer = ofile.peek(size);
    if(!buffer.startsWith(header)) {
        qCritical() << "We did not create this file";
        ofile.close();
        nfile.close();
        return false;
    }

    // Find the header position
    ofile.seek(header.length());
    qInfo() << "Starting at: " << ofile.pos();

    while (!ofile.atEnd()) {
        buffer = ofile.peek(size);
        qint64 index = buffer.indexOf(header);
        qInfo() << "Header found at: " << index;
        if (index > -1) {
            // Have the header
            qint64 maxbytes = index;
            qInfo() << "Reading: " << maxbytes;
            buffer = ofile.read(maxbytes);
            ofile.read(header.length());
        } else {
            // Do not have the header
            qInfo() << "Read all, no header";
            buffer = ofile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        qInfo() << "Decompressed: " << nfile.write(decompressed);
        nfile.flush();
    }

    ofile.close();
    nfile.close();

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString originalFile = QDir::currentPath() + QDir::separator() + "original.txt";
    QString compressedFile = QDir::currentPath() + QDir::separator() + "compressed.txt";
    QString decompressedFile = QDir::currentPath() + QDir::separator() + "decompressed.txt";

    if (makeFile(originalFile)) {
        qInfo() << "Original Created";
        if(compressFile(originalFile, compressedFile)) {
            qInfo() << "File compressed";
            if (decompressFile(compressedFile, decompressedFile)) {
                qInfo() << "File decompressed";
            } else {
                qInfo() << "Could not decompress file";
            }
        } else {
            qInfo() << "File not compressed";
        }
    }

    return a.exec();
}

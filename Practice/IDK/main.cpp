#include <QCoreApplication>

#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "utility/filesystem.h"
#include "utility/helpers.h"

#include <QRandomGenerator64>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QVariant>
#include <QList>

#include <iostream>

QString getExtension(QString url);
bool isValidImageFile(QString path_with_extension);

QList<QString> validExtensions = { "jpg", "jpe", "bmp", "gif", "png", "jpeg" };
bool isValidImageFile(QString path_with_extension) { return validExtensions.contains(getExtension(path_with_extension).toLower()); }

QString getExtension(QString url) {
    std::string filename(url.toStdString());
    std::string::size_type idx;

    idx = filename.rfind(".");
    if (idx != std::string::npos)
    {
        // Extension found
        return QString::fromStdString(filename.substr(idx + 1));
    }
    else
    {
        // No extention found
        return "";
    }
}

QString removeLastSlash(QString url) {
    if (url.size() > 0) {
        if (url.at(url.length() - 1) == "/" || url.at(url.length() - 1) == "\\") {
            return url.left(url.length() - 1);
        }
    }
    return url;
}

// testing command [NOTE: .png output will increase the size of the image while .jpg reduce the size]

// Single Image
// IDK.exe "C:\\Users\\Raisehand\\Pictures\\Camera Roll\\2.jpg" "C:\\Users\\Raisehand\\Desktop\\working" "[50, 50, 50, 50]" temp.json
// IDK.exe "C:\\Users\\Raisehand\\Pictures\\Camera Roll\\WIN_20220618_10_30_46_Pro.jpg" "C:\\Users\\Raisehand\\Desktop\\working" "[50, 50, 50, 50]" temp.json

// Multiple Images
// IDK.exe "[\"C:\\Users\\Raisehand\\Pictures\\Camera Roll\\2.jpg\", \"C:\\Users\\Raisehand\\Pictures\\Camera Roll\\WIN_20220618_10_30_46_Pro.jpg\"]" "C:\\Users\\Raisehand\\Desktop\\working" "[50, 50, 50, 50]" temp.json

void help() {
    qInfo() << "This application required some args kindly provide them";
    qInfo() << "xxxxxxxxxxxxxxxxxxxxxxxx";
    qInfo() << ".exe [src] destination [args] resultFile :: Example => \"[ \"C:/Pictures/1.jpg\", \"C:/Pictures/2.jpg\" ]\" \"C:/User/YourName/Dump\" \"[50, 50, 50, 50]\" output.json";
    qInfo() << ".exe  src  destination [args] resultFile :: Example => \"C:/Pictures/1.jpg\" \"C:/User/YourName/Dump\" \"[50, 50, 50, 50]\" output.json";

    qInfo() << "NOTE: PLEASE DO NOT PROVIDE MORE THEN 10 IMAGES AT SAME TIME";
    qInfo() << "xxxxxxxxxxxxxxxxxxxxxxxx";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Helpers helpers;
    FileSystem fs;

    qInfo() << "------------------------------------------";
    qInfo() << "This piece of software build by Gaurav Gupta @ Raisehand Software Private Limited";
    qInfo() << "This is build upon open source image processing library called OPEN_CV";
    qInfo() << "We are just taking help of the library in order to manupulate images";
    qInfo() << "------------------------------------------";

    // argv[0] always holds the program name.
    // argv[1] holds the first command line argument while argv[n] in the last command lint argument.

    int total_args_count = argc;
    if (total_args_count == 1) {
        help();
        return -1;
    }

    if (total_args_count < 3) {
        help();
        return -1;
    }

    QString args = argv[3];
    QString source = argv[1];
    QString resultFile = argv[4];
    QString destination = argv[2];

    // Please always check if we got all the argument as expected or not
    qInfo() << "Number of command line arguments (args) entered: " << total_args_count << endl;

    QJsonArray args_array = QJsonDocument::fromJson(QString(args).toUtf8()).array();
    if (args_array.size() < 4) {
        qWarning() << "Please provide all args, i.e. [top right bottom left]";
        return -1;
    }

    int total_int_type_args_matched = 0;
    int total_int_value_args_matched = 0;
    int required_min_value = 50;
    int required_max_value = 150;

    for (int i = 0; i < args_array.size() ; i++ ) {
        if (args_array.at(i).isDouble()) total_int_type_args_matched += 1;
        if (args_array.at(i).toDouble() >= required_min_value) total_int_value_args_matched += 1;
        if (args_array.at(i).toDouble() > required_max_value) total_int_value_args_matched -= 1;
    }
    if (total_int_type_args_matched != args_array.size()) {
        qInfo() << "args type error";
        return -1;
    }
    if (total_int_value_args_matched != args_array.size()) {
        qInfo() << "args value should be >=" << required_min_value << "and" << "<=" << required_max_value;
        return -1;
    }

    // setting the overall file path
    fs.setCurrentPath(removeLastSlash(destination));

    // deleting files
    // Assume the directory exists and contains some files and you want all jpg and JPG files
    QDir directory(destination);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.JPG" << "*.jpeg" << "*.JPEG" << "*.png" << "*.PNG" << "*.jpe" << "*.JPE" << "*.gif" << "*.GIF" << "*.bmp" << "*.BMP" ,QDir::Files);
    foreach(QString filename, images) {
        QString file_created_at = QFileInfo(destination + fs.path_separator() + filename).created().addSecs(120).toString("yyyy-MM-dd HH:mm:ss");
        QString currentTime = helpers.getCurrentTime().toString("yyyy-MM-dd HH:mm:ss");
        // if file date is even 1 minute older then delete this image file
        if (file_created_at < currentTime) {
            fs.deleteFile(filename);
        }
    }

    if (QString(source).contains("[") && QString(source).contains("\"")) { // multiple items
        qInfo() << "Padding multiple items at once";

        int total_image_padded = 0;
        QJsonObject o;
        QJsonArray names, imageDumps;
        QJsonArray paths = QJsonDocument::fromJson(QString(source).toUtf8()).array();

        if (paths.size() > 10) {
            qInfo() << "Please provide less then 10 images at once";
            return -1;
        }

        for (int i = 0; i < paths.size() ; i++ ) {
            QString path = paths.at(i).toString();
            if (!isValidImageFile(path)) continue;

            cv::Mat image, pad;
            // read an image
            image = cv::imread(path.toStdString(), 1);
            // pad the image
            cv::copyMakeBorder(image, pad, args_array.at(0).toDouble() /* top */, args_array.at(2).toDouble() /* bottom */, args_array.at(3).toDouble() /* left */, args_array.at(1).toDouble() /* right */, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255) );
            // saving image back to machine
            QString f_name = QString::number(QRandomGenerator::global()->bounded(100000)) + ".jpg";
            QString dump(removeLastSlash(destination) + fs.path_separator() + f_name);
            cv::imwrite(dump.toStdString(), pad);

            names.push_back(f_name);
            imageDumps.push_back(dump);

            total_image_padded++;
        }

        o.insert("assign_task", paths.size());
        o.insert("total_task_done", total_image_padded);

        o.insert("urls", paths);
        o.insert("names", names);
        o.insert("imageDumps", imageDumps);
        o.insert("args", args_array);
        o.insert("dump", removeLastSlash(destination));
        o.insert("quality", 100);
        o.insert("resultFile", resultFile);

        QJsonDocument doc(o);

        // saving the result in seperate file so that other can see what happend
        fs.write(doc.toJson(), resultFile);

        // dump a message on console as well
        // qInfo() << doc.toVariant();
    }
    else { // single item
        if (!QString(source).isEmpty()) {
            if (!isValidImageFile(source)) {
                qInfo() << "This is not an image, please provide an image";
                return -1;
            }

            qInfo() << "Padding single item";
            cv::Mat image, pad;
            // read an image
            image = cv::imread(source.toStdString(), 1);
            // pad the image
            cv::copyMakeBorder(image, pad, args_array.at(0).toDouble() /* top */, args_array.at(2).toDouble() /* bottom */, args_array.at(3).toDouble() /* left */, args_array.at(1).toDouble() /* right */, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255) );
            // saving image back to machine
            QString f_name = QString::number(QRandomGenerator::global()->bounded(100000)) + ".jpg";
            QString dump(removeLastSlash(destination) + fs.path_separator() + f_name);
            cv::imwrite(dump.toStdString(), pad);

            QJsonObject o;
            o.insert("url", source);
            o.insert("imageDump", dump);
            o.insert("fname_we", f_name);
            o.insert("args", args_array);
            o.insert("dump", removeLastSlash(destination));
            o.insert("quality", 100);
            o.insert("resultFile", resultFile);

            QJsonDocument doc(o);

            // saving the result in seperate file so that other can see what happend
            fs.setCurrentPath(removeLastSlash(destination));
            fs.write(doc.toJson(), resultFile);

            // dump a message on console as well
            // qInfo() << doc.toVariant();
        }
    }

    return 0; // succeed

    // build the release version
    // test this on another pc and see if it works or not?
    // find out the electron side logic
    // error handle and check the task manager about how many ram is being used in this
}

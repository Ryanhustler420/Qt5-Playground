import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("String, Date and Time")

    property string mValue: "Clicked %1 times, double is %2"
    property int clickCount: 0

    Connections {
        target: CppClass
        onSendDateTime: {
            console.log("Receive datetime : " + datetimeparem);
            // Extract info
            console.log("year: " + datetimeparem.getFullYear());
            console.log("...", datetimeparem.toGMTString());
        }
        onSendTime: {
            console.log("Receive datetime : " + timeparem);
        }
    }

    Button {
        id: mButton
        text: "click"
        onClicked: {
            // CppClass.cppSlot()

            var date = new Date()
            // CppClass.timeSlot(date)
            CppClass.dateTimeSlot(date)

            clickCount++
            mButton.text = mValue.arg(clickCount).arg(clickCount * 2)
        }
    }

    Component.onCompleted: {
        var mDate = new Date();

        // 1. toLocaleString(contains date)
        print(mDate.toLocaleDateString())
        print(mDate.toLocaleDateString(Qt.locale("de_DE")))
        print(mDate.toLocaleDateString(Qt.locale("fr_FR")))
        print(mDate.toLocaleDateString(Qt.locale("zh_CN"), "yyyy-MM-dd"))

        // 2. toLocalString(contains date and time)
        print(mDate.toLocaleString(Qt.locale("en_US"), "yyyy-MM-dd HH:mm:ss"))

        // 3. toLocaleTimeString(contains time)
        print(mDate.toLocaleString(Qt.locale("en_US"), "HH:mm:ss"))

        // 4. fromLocaleDateString
        // 2018-May-18
        // yyyy-MM-dd HH:mm:ss , locale : zh_CH
        var myDate = Date.fromLocaleDateString(Qt.locale("en_US"), "2018-09-17", "yyyy-MM-dd")
        print("Date is:", myDate)

        // 5. fromLocaleString
        myDate = Date.fromLocaleString(Qt.locale("en_US"), "2018-09-17 --16:59:59", "yyyy-MM-dd --HH:mm:ss");
        print(myDate)

        // 6. fromLocaleTimeString
        myDate = Date.fromLocaleTimeString(Qt.locale("en_US"), "16:23:35", "HH:mm:ss")
        print(myDate)

        print("--------------------------------Number locale operations---------------------------------")

        // Read numbers from a given locale
        var mLocale = Qt.locale("de_DE")
        var d
        d = Number.fromLocaleString(mLocale, "1234,56")
        print("d is:", d)

        d = Number.fromLocaleString(mLocale, "1.234,56")
        print("d is:", d)

        // Currency output
        mLocale = Qt.locale("Dp_KP")
        var number = Number("123.00") // The symbol shows up for installed languages on my system
        var outstr = number.toLocaleCurrencyString(mLocale, mLocale.currencySymbol(Locale.CurrencySymbol))
        print("currency is:", outstr)

        mLocale = Qt.locale("en_US")
        number = Number("123.00")
        outstr = number.toLocaleString(mLocale, 'f', 4) // Precision, number of digits after decimal point
        print("The number is : " + outstr)
    }

}

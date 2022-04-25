#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QTimer>
#include<QAbstractTableModel>

class CustomTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomTableModel(QObject * parent);
    ~CustomTableModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const; // Constrols the data that is show in cell
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QTimer * timer;
};

#endif // CUSTOMTABLEMODEL_H

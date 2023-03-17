#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include <Qtimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();
    void on_reqButton_clicked();

    void inputDB();

private:
    Ui::MainWindow *ui;

    QString m_name;
    int m_num = 0;

    QString m_reqName;
    int m_numOut = 0;

    std::map<QString, int> db;
};
#endif // MAINWINDOW_H

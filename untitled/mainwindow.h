#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digets_num();
    void on_pushButton_dot_clicked();
    void operation();
    void math();
    void on_pushButton_eq_clicked();
};

#endif // MAINWINDOW_H

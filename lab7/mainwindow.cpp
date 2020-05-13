#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listW1->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listW2->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    QString text = ui->inEdit->text();
    if (!text.isEmpty() && !ui->listW1->findItems(text, Qt::MatchExactly).count()) {
        ui->listW1->addItem(text);
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->listW1->clear();
    ui->listW2->clear();
}

void MainWindow::on_moveButton_clicked()
{
    QList<QListWidgetItem*> items = ui->listW1->selectedItems();
    for (const auto& elem: items) {
        ui->listW2->addItem(elem->text());
        delete ui->listW1->takeItem(ui->listW1->row(elem));
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QList<QListWidgetItem*> items = ui->listW1->selectedItems();
    for (const auto& elem: items) {
        delete ui->listW1->takeItem(ui->listW1->row(elem));
    }
    items = ui->listW2->selectedItems();
    for (const auto& elem: items) {
        delete ui->listW2->takeItem(ui->listW2->row(elem));
    }
}

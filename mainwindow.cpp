#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include "editorscene.h"
#include "basicshapeitem.h"
#include "complexshapeitem.h"
#include <QDebug>
#include <QStyleFactory>
#include <QApplication>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    EditorScene *scene = new EditorScene();
    BasicShapesItem *item = new BasicShapesItem(12,12,200,200,BasicShapesItem::ITEM_PIXMAP,scene);
    BasicShapesItem *item2 = new BasicShapesItem(12,12,200,200,BasicShapesItem::ITEM_ELLIPSE,scene);
    BasicShapesItem *item3 = new BasicShapesItem(12,12,200,200,BasicShapesItem::ITEM_RECTANGLE,scene);
    ComplexShapeItem *item4 = new ComplexShapeItem(ComplexShapeItem::SEGEMENT_CURVE, scene);

    //BasicShapesItem *itemText = new BasicShapesItem(12,12,200,200,BasicShapesItem::ITEM_TEXT,scene);

    item4->addPoint(QPointF(0,0));
    item4->addPoint(QPointF(12,12));
    item4->addPoint(QPointF(50,50));
    item4->addPoint(QPointF(100,230));
    item4->addPoint(QPointF(250,200));
    item4->addPoint(QPointF(250,280));
    item4->addPoint(QPointF(300,340));


    //itemText->setPos(250,300);
    item->setPos(0,100);
    item2->setPos(200,100);
    item3->setPos(400,100);
    item->setPixmap("://Resources/character_design.jpg");
    item4->setPos(600,100);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

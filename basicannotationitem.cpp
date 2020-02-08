#include "basicannotationitem.h"
#include <QPainter>
#include <QGraphicsScene>
#include "handle.h"

BasicAnnotationItem::BasicAnnotationItem(qreal x, qreal y, AnnotationType type,QGraphicsScene *scene, QGraphicsItem *parent) : BaseItem(scene,parent)
{
    //TODO : change size base
    mRect.setRect(x,y,20,20);
    mType = type;
    createHandles();
}


void BasicAnnotationItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //Fix coordinates for images.
    if(mRect.left() > mRect.right()) {
        qreal left = mRect.left();
        qreal right = mRect.right();
        mRect.setLeft(right);
        mRect.setRight(left);
    }
    if(mRect.top() > mRect.bottom()) {
        qreal top = mRect.top();
        qreal bottom = mRect.bottom();
        mRect.setTop(bottom);
        mRect.setBottom(top);
    }

    //Enable antialiasing.
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->save();

    painter->setBrush(QBrush(QColor(5,125,230, 50)));
    painter->setPen(QPen(QColor(0, 0, 0), 1.0, Qt::SolidLine));

    switch (mType) {
    case ITEM_TEXT:
        //painter->drawRect(this->mRect);
        break;
    case ITEM_ANNOTATION:
        //painter->drawEllipse(this->mRect);
        break;
    case ITEM_LINE:
        painter->drawLine(this->mRect.topLeft(),this->mRect.bottomRight());
        break;
    case ITEM_ARROW:
        //painter->drawPixmap(this->mRect.toRect(),this->mPixmap);
        break;
    default:
        break;
    }

    painter->restore();

    BaseItem::paint(painter,option,widget);

    scene()->update();
}


QRectF BasicAnnotationItem::boundingRect() const{
    return BaseItem::boundingRect();
}

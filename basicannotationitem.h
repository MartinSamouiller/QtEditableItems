#ifndef BASICANNOTATIONITEM_H
#define BASICANNOTATIONITEM_H

#include "baseitem.h"

class BasicAnnotationItem : public BaseItem
{
public:
    BasicAnnotationItem();

    enum AnnotationType {ITEM_TEXT, ITEM_ANNOTATION,ITEM_ARROW, ITEM_LINE};
    BasicAnnotationItem(qreal x, qreal y, AnnotationType type,QGraphicsScene *scene, QGraphicsItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setType();

private:
    AnnotationType mType;
};

#endif // BASICANNOTATIONITEM_H

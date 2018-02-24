#ifndef MARZIPAN_RASTERWINDOW_H
#define MARZIPAN_RASTERWINDOW_H

#include <qt5/QtGui/QWindow>

class RasterWindow : public QWindow {
    Q_OBJECT
public:
    explicit RasterWindow(QWindow * parent = 0);
    virtual void render(QPainter * painter);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent * event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    QBackingStore *m_backingStore;
};


#endif //MARZIPAN_RASTERWINDOW_H

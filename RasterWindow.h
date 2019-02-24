#ifndef MARZIPAN_RASTERWINDOW_H
#define MARZIPAN_RASTERWINDOW_H

#include <QtWidgets/QMainWindow>
#include "RasterWidget.h"

class RasterWindow : public QMainWindow {
    Q_OBJECT
public:
    RasterWindow();

private:
    QAction *undoAct;
    QAction *redoAct;
    RasterWidget * widget = new RasterWidget();
    void createActions();

#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

protected:
    void keyReleaseEvent(QKeyEvent * event) override;

private slots:
    void undo();
    void redo();
};


#endif //MARZIPAN_RASTERWINDOW_H

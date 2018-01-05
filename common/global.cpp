#include "global.h"
//WinInfoListDialog *WinInfoListDialog::instance()
//{
//    static WinInfoListDialog data;
//    return &data;
//}


GlobalData *GlobalData::instance()
{
  static GlobalData g;
  return & g;
}

GlobalData::GlobalData(QObject *parent) : QObject(parent)
{
  m_comPath = QString("com2");
  m_udiskPath = QString("F:\QtCode\sunDemon\mokeUdisk");
}

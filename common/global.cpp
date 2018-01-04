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
  m_comPath = QString("");
  m_udiskPath = QString("");
}

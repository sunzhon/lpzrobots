/***************************************************************************
 *   Copyright (C) 2005 by Robot Group Leipzig                             *
 *    martius@informatik.uni-leipzig.de                                    *
 *    fhesse@informatik.uni-leipzig.de                                     *
 *    der@informatik.uni-leipzig.de                                        *
 *    guettler@informatik.uni-leipzig.de                                   *
 *    jhoffmann@informatik.uni-leipzig.de                                  *
 *    wolfgang.rabe@01019freenet.de                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *                                                                         *
 *  DESCRIPTION                                                            *
 *                                                                         *
 *   $Log$
 *   Revision 1.2  2010-11-14 20:39:37  wrabe
 *   - save current developent state
 *
 *   Revision 1.1  2010/11/11 15:35:59  wrabe
 *   -current development state of QMessageDispatchServer
 *   -introduction of QCommunicationChannels and QCCHelper
 *
 *   Revision 1.1  2010/11/10 09:32:00  guettler
 *   - port to Qt part 1
 *                                            *
 *                                                                         *
 ***************************************************************************/

#ifndef ABSTRACT_QMESSAGECLIENT_H_
#define ABSTRACT_QMESSAGECLIENT_H_
#include "types.h"
#include <QThread>

namespace lpzrobots {

  struct _communicationMessage
  {
      QString    ecb_dns_name; // (max 32 char)
      QByteArray data;         // MsgCode + n*Data
  };

  class QAbstractMessageClient : public QThread {
  Q_OBJECT
  public:

  QAbstractMessageClient() : QThread() {}

  virtual ~QAbstractMessageClient() {}

  signals:
    void sig_sendMessage(struct _communicationMessage msg);
    // optional
    //virtual void sig_quitClient() = 0;

  public slots:
    virtual void sl_messageReceived(struct _communicationMessage msg) = 0;
    virtual void sl_quitServer() = 0;

  private:

  };

} // namespace lpzrobots

#endif /* ABSTRACT_QMESSAGECLIENT_H_ */
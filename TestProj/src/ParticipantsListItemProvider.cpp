/*
 * ParticipantsListItemProvider.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#include "ParticipantsListItemProvider.h"
#include "ParticipantListItem.h"
using namespace bb::cascades;

namespace ooh {

ParticipantsListItemProvider::ParticipantsListItemProvider() {
	// TODO Auto-generated constructor stub

}

ParticipantsListItemProvider::~ParticipantsListItemProvider() {
	// TODO Auto-generated destructor stub
}

VisualNode * ParticipantsListItemProvider::createItem(ListView* list, const QString &type)
{
  // We only have one iQtem type so we do not need to check the type variable
  Q_UNUSED(type);
  Q_UNUSED(list);


  ParticipantListItem *item = new ParticipantListItem();
  return item;

}

void ParticipantsListItemProvider::updateItem(ListView* list, bb::cascades::VisualNode *listItem,
    const QString &type, const QVariantList &indexPath, const QVariant &data)
{
  Q_UNUSED(list);
  Q_UNUSED(indexPath);
  Q_UNUSED(type);
  // Update the control with correct data

  QVariantMap map = data.value<QVariantMap>();
  ParticipantListItem *item = static_cast<ParticipantListItem *>(listItem);
  item->updateItem(map["name"].value<QString>(), map["email"].value<QString>(), map["exl"].value<QStringList>());

}

} /* namespace ooh */

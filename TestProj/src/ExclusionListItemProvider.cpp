/*
 * ExclusionListItemProvider.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#include "ExclusionListItemProvider.h"
#include "ExclustionEmailListItem.h"
using namespace bb::cascades;

namespace ooh {

ExclusionListItemProvider::ExclusionListItemProvider() {
	// TODO Auto-generated constructor stub
}

ExclusionListItemProvider::~ExclusionListItemProvider() {
	// TODO Auto-generated destructor stub
}

VisualNode * ExclusionListItemProvider::createItem(ListView* list, const QString &type)
{
  // We only have one iQtem type so we do not need to check the type variable
  Q_UNUSED(type);
  Q_UNUSED(list);


  ExclustionEmailListItem *item = new ExclustionEmailListItem();
  return item;

}

void ExclusionListItemProvider::updateItem(ListView* list, bb::cascades::VisualNode *listItem,
    const QString &type, const QVariantList &indexPath, const QVariant &data)
{
  Q_UNUSED(list);
  Q_UNUSED(indexPath);
  Q_UNUSED(type);
  // Update the control with correct data

  QString email = data.value<QString>();
  ExclustionEmailListItem *item = static_cast<ExclustionEmailListItem *>(listItem);
  item->updateItem(email);

}

} /* namespace ooh */

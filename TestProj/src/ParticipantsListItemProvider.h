/*
 * ParticipantsListItemProvider.h
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#ifndef PARTICIPANTSLISTITEMPROVIDER_H_
#define PARTICIPANTSLISTITEMPROVIDER_H_
#include <bb/cascades/ListItemProvider>

using namespace bb::cascades;

namespace bb
{
  namespace cascades
  {
    class ListView;
  }
}
namespace ooh {

class ParticipantsListItemProvider : public bb::cascades::ListItemProvider {
public:
	ParticipantsListItemProvider();
	virtual ~ParticipantsListItemProvider();

	VisualNode * createItem(ListView* list, const QString &type);
	void updateItem(ListView* list, VisualNode *listItem, const QString &type,
	  const QVariantList &indexPath, const QVariant &data);
};

} /* namespace ooh */
#endif /* PARTICIPANTSLISTITEMPROVIDER_H_ */

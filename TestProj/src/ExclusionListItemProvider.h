/*
 * ExclusionListItemProvider.h
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#ifndef EXCLUSIONLISTITEMPROVIDER_H_
#define EXCLUSIONLISTITEMPROVIDER_H_
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

class ExclusionListItemProvider : public bb::cascades::ListItemProvider {
public:
	ExclusionListItemProvider();
	virtual ~ExclusionListItemProvider();

	VisualNode * createItem(ListView* list, const QString &type);
	void updateItem(ListView* list, VisualNode *listItem, const QString &type,
	      const QVariantList &indexPath, const QVariant &data);
};

} /* namespace ooh */
#endif /* EXCLUSIONLISTITEMPROVIDER_H_ */

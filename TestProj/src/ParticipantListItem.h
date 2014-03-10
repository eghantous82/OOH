/*
 * ParticipantListItem.h
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#ifndef PARTICIPANTLISTITEM_H_
#define PARTICIPANTLISTITEM_H_
#include <bb/cascades/CustomControl>
#include <bb/cascades/ListItemListener>

using namespace bb::cascades;

namespace bb
{
  namespace cascades
  {
    class Label;
    class Container;
  }
}
namespace ooh {

class ParticipantListItem : public bb::cascades::CustomControl, public ListItemListener {

	Q_OBJECT

public:
	ParticipantListItem();
	virtual ~ParticipantListItem();

	 /**
	   * This function updates the data of the item.
	   *
	   * @param text The label text.
	   */
	  void updateItem(const QString name, QString email, QStringList exList);

	  /**
	   * This ListItemListener interface function is called when the select state changes.
	   *
	   * @param select True if the item has been selected, false if unselected
	   */
	  void select(bool select);

	  /**
	   * This ListItemListener interface function is called when an item needs to be reset.
	   * Since items are recycled, the reset function is where we have
	   * to make sure that item state (defined by the arguments) is correct.
	   *
	   * @param selected True if the item should appear selected, false if unselected
	   * @param activated True if the item should appear activated, false if deactivated
	   */
	  void reset(bool selected, bool activated);

	  /**
	   * This ListItemListener interface function called when an item is activated/deactivated.
	   *
	   * @param activate True if the item has been activated, false if inactive.
	   */
	  void activate(bool activate);

private:

 // Item Controls
 Label *mNameLabel;
 Label *mEmailLabel;
 Label *mExListLabel;
 Container *mHighlighContainer;

};

} /* namespace ooh */
#endif /* PARTICIPANTLISTITEM_H_ */

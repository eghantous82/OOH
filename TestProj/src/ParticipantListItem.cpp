/*
 * ParticipantListItem.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#include "ParticipantListItem.h"

#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>
#include <bb/cascades/StackLayout>
#include <bb/cascades/SystemDefaults>
#include <bb/cascades/TextStyle>
using namespace bb::cascades;



namespace ooh {

ParticipantListItem::ParticipantListItem() {
	// A background Container that will hold a background image and an item content Container
		  Container *itemContainer = new Container();
		  DockLayout *itemLayout = new DockLayout();
		  itemContainer->setLayout(itemLayout);
		  itemContainer->setPreferredWidth(768.0f);

		  itemContainer->setBackground(Color::White);


		  // Content Container containing an image and label with padding for the alignment on background image
		  Container *contentContainer = new Container();
		  StackLayout *contentLayout = new StackLayout();
		  contentLayout->setOrientation(LayoutOrientation::TopToBottom);
		  contentContainer->setLeftPadding(3.0f);
		  contentContainer->setLayout(contentLayout);

		  Container *sep = new Container();
		  sep->setPreferredHeight(5.0);
		  sep->setPreferredWidth(768.0);
		  sep->setBackground(Color::Black);

		  TextStyle style;
		  style.setColor(Color::White);
		  style.setTextAlign(TextAlign::Center);
		  // A list item label, docked to the center, the text is set in updateItem.
		  mNameLabel = Label::create().text(" ").textStyle(style);
		  mNameLabel->setVerticalAlignment(VerticalAlignment::Center);
		  mNameLabel->setLeftMargin(30.0f);
		  mNameLabel->textStyle()->setBase(SystemDefaults::TextStyles::titleText());
		  mNameLabel->textStyle()->setColor(Color::Black);

		  mEmailLabel = Label::create().text(" ").textStyle(style);
		  mEmailLabel->setVerticalAlignment(VerticalAlignment::Center);
		  mEmailLabel->setLeftMargin(30.0f);
		  mEmailLabel->textStyle()->setBase(SystemDefaults::TextStyles::titleText());
		  mEmailLabel->textStyle()->setColor(Color::Black);

		mExListLabel = Label::create().text(" ").textStyle(style);
		mExListLabel->setVerticalAlignment(VerticalAlignment::Center);
		mExListLabel->setLeftMargin(30.0f);
		mExListLabel->textStyle()->setBase(SystemDefaults::TextStyles::titleText());
		mExListLabel->textStyle()->setColor(Color::Black);

		  // Add the Image and Label to the content Container
		  contentContainer->add(mNameLabel);
		  contentContainer->add(mEmailLabel);
		  contentContainer->add(mExListLabel);
		  contentContainer->add(sep);

		  // A Colored Container will be used to show if an item is highlighted
		  mHighlighContainer = new Container();
		  mHighlighContainer->setBackground(Color::fromARGB(0xff75b5d3));
		  mHighlighContainer->setHorizontalAlignment(HorizontalAlignment::Center);
		  mHighlighContainer->setOpacity(0.0);
		  mHighlighContainer->setPreferredWidth(760.0f);
		  mHighlighContainer->setPreferredHeight(contentContainer->preferredHeight());

		  itemContainer->add(mHighlighContainer);
		  itemContainer->add(contentContainer);
		  setRoot(itemContainer);
}

ParticipantListItem::~ParticipantListItem() {
	// TODO Auto-generated destructor stub
}

void ParticipantListItem::updateItem(const QString name, QString email, QStringList exList)
{
  // Update image and text for the current item
	QString exListStr;
  mNameLabel->setText(name);
  mEmailLabel->setText(email);
  for(int i = 0; i < exList.size() - 1; ++i)
  {
	  exListStr.append(exList[i]).append(", ");
  }
  if(exList.size() > 0)
  {
	  exListStr.append(exList[exList.size()-1]);
  }
  mExListLabel->setText(exListStr);
}

void ParticipantListItem::select(bool select)
{
  // When an item is selected, show the colored highlight Container
  if (select) {
    mHighlighContainer->setOpacity(0.9f);
  } else {
    mHighlighContainer->setOpacity(0.0f);
  }
}

void ParticipantListItem::reset(bool selected, bool activated)
{
  Q_UNUSED(activated);

  // Since items are recycled, the reset function is where we have
  // to make sure that item state (defined by the arguments) is correct.
  select(selected);
}

void ParticipantListItem::activate(bool activate)
{
  // There is no special activate state; selected and activated look the same.
  select(activate);
}

} /* namespace ooh */

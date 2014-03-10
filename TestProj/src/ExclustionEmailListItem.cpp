/*
 * ExclustionEmailListItem.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#include "ExclustionEmailListItem.h"

#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>
#include <bb/cascades/StackLayout>
#include <bb/cascades/SystemDefaults>
#include <bb/cascades/TextStyle>
using namespace bb::cascades;

namespace ooh {

ExclustionEmailListItem::ExclustionEmailListItem(Container* parent):CustomControl(parent)
{
	  // A background Container that will hold a background image and an item content Container
	  Container *itemContainer = new Container();
	  DockLayout *itemLayout = new DockLayout();
	  itemContainer->setLayout(itemLayout);
	  itemContainer->setPreferredWidth(768.0f);

	  itemContainer->setBackground(Color::White);

	  // A Colored Container will be used to show if an item is highlighted
	  mHighlighContainer = new Container();
	  mHighlighContainer->setBackground(Color::fromARGB(0xff75b5d3));
	  mHighlighContainer->setHorizontalAlignment(HorizontalAlignment::Center);
	  mHighlighContainer->setOpacity(0.0);
	  mHighlighContainer->setPreferredWidth(760.0f);
	  mHighlighContainer->setPreferredHeight(100.0f);

	  // Content Container containing an image and label with padding for the alignment on background image
	  Container *contentContainer = new Container();
	  StackLayout *contentLayout = new StackLayout();
	  contentLayout->setOrientation(LayoutOrientation::LeftToRight);
	  contentContainer->setLeftPadding(3.0f);
	  contentContainer->setLayout(contentLayout);

	  TextStyle style;
	  style.setColor(Color::White);
	  style.setTextAlign(TextAlign::Center);
	  // A list item label, docked to the center, the text is set in updateItem.
	  mItemLabel = Label::create().text(" ").textStyle(style);
	  mItemLabel->setVerticalAlignment(VerticalAlignment::Center);
	  mItemLabel->setLeftMargin(30.0f);
	  mItemLabel->textStyle()->setBase(SystemDefaults::TextStyles::titleText());
	  mItemLabel->textStyle()->setColor(Color::Black);

	  // Add the Image and Label to the content Container
	  contentContainer->add(mItemLabel);

	  // Add the background image and the content to the full item container.

	  itemContainer->add(mHighlighContainer);
	  itemContainer->add(contentContainer);

	  setRoot(itemContainer);
}

ExclustionEmailListItem::~ExclustionEmailListItem() {
}

void ExclustionEmailListItem::updateItem(const QString text)
{
  // Update image and text for the current item
  mItemLabel->setText(text);
}

void ExclustionEmailListItem::select(bool select)
{
  // When an item is selected, show the colored highlight Container
  if (select) {
    mHighlighContainer->setOpacity(0.9f);
  } else {
    mHighlighContainer->setOpacity(0.0f);
  }
}

void ExclustionEmailListItem::reset(bool selected, bool activated)
{
  Q_UNUSED(activated);

  // Since items are recycled, the reset function is where we have
  // to make sure that item state (defined by the arguments) is correct.
  select(selected);
}

void ExclustionEmailListItem::activate(bool activate)
{
  // There is no special activate state; selected and activated look the same.
  select(activate);
}

} /* namespace ooh */

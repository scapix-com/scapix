// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_VIEW_MENUITEM_H
#define SCAPIX_ANDROID_VIEW_MENUITEM_H

namespace scapix::java_api {

namespace android::content { class Intent; }
namespace android::content::res { class ColorStateList; }
namespace android::graphics { class PorterDuff_Mode; }
namespace android::graphics::drawable { class Drawable; }
namespace android::view { class ActionProvider; }
namespace android::view { class ContextMenu_ContextMenuInfo; }
namespace android::view { class MenuItem_OnActionExpandListener; }
namespace android::view { class MenuItem_OnMenuItemClickListener; }
namespace android::view { class SubMenu; }
namespace android::view { class View; }
namespace java::lang { class CharSequence; }

namespace android::view {

class MenuItem : public object_base<SCAPIX_META_STRING("android/view/MenuItem"),
	java::lang::Object>
{
public:

	using OnMenuItemClickListener = MenuItem_OnMenuItemClickListener;
	using OnActionExpandListener = MenuItem_OnActionExpandListener;

	static jint SHOW_AS_ACTION_ALWAYS_();
	static jint SHOW_AS_ACTION_COLLAPSE_ACTION_VIEW_();
	static jint SHOW_AS_ACTION_IF_ROOM_();
	static jint SHOW_AS_ACTION_NEVER_();
	static jint SHOW_AS_ACTION_WITH_TEXT_();

	jint getItemId();
	jint getGroupId();
	jint getOrder();
	ref<android::view::MenuItem> setTitle(ref<java::lang::CharSequence> p1);
	ref<android::view::MenuItem> setTitle(jint p1);
	ref<java::lang::CharSequence> getTitle();
	ref<android::view::MenuItem> setTitleCondensed(ref<java::lang::CharSequence> p1);
	ref<java::lang::CharSequence> getTitleCondensed();
	ref<android::view::MenuItem> setIcon(ref<android::graphics::drawable::Drawable> p1);
	ref<android::view::MenuItem> setIcon(jint p1);
	ref<android::graphics::drawable::Drawable> getIcon();
	ref<android::view::MenuItem> setIconTintList(ref<android::content::res::ColorStateList> tint);
	ref<android::content::res::ColorStateList> getIconTintList();
	ref<android::view::MenuItem> setIconTintMode(ref<android::graphics::PorterDuff_Mode> tintMode);
	ref<android::graphics::PorterDuff_Mode> getIconTintMode();
	ref<android::view::MenuItem> setIntent(ref<android::content::Intent> p1);
	ref<android::content::Intent> getIntent();
	ref<android::view::MenuItem> setShortcut(jchar p1, jchar p2);
	ref<android::view::MenuItem> setShortcut(jchar numericChar, jchar alphaChar, jint numericModifiers, jint alphaModifiers);
	ref<android::view::MenuItem> setNumericShortcut(jchar p1);
	ref<android::view::MenuItem> setNumericShortcut(jchar numericChar, jint numericModifiers);
	jchar getNumericShortcut();
	jint getNumericModifiers();
	ref<android::view::MenuItem> setAlphabeticShortcut(jchar p1);
	ref<android::view::MenuItem> setAlphabeticShortcut(jchar alphaChar, jint alphaModifiers);
	jchar getAlphabeticShortcut();
	jint getAlphabeticModifiers();
	ref<android::view::MenuItem> setCheckable(jboolean p1);
	jboolean isCheckable();
	ref<android::view::MenuItem> setChecked(jboolean p1);
	jboolean isChecked();
	ref<android::view::MenuItem> setVisible(jboolean p1);
	jboolean isVisible();
	ref<android::view::MenuItem> setEnabled(jboolean p1);
	jboolean isEnabled();
	jboolean hasSubMenu();
	ref<android::view::SubMenu> getSubMenu();
	ref<android::view::MenuItem> setOnMenuItemClickListener(ref<android::view::MenuItem_OnMenuItemClickListener> p1);
	ref<android::view::ContextMenu_ContextMenuInfo> getMenuInfo();
	void setShowAsAction(jint p1);
	ref<android::view::MenuItem> setShowAsActionFlags(jint p1);
	ref<android::view::MenuItem> setActionView(ref<android::view::View> p1);
	ref<android::view::MenuItem> setActionView(jint p1);
	ref<android::view::View> getActionView();
	ref<android::view::MenuItem> setActionProvider(ref<android::view::ActionProvider> p1);
	ref<android::view::ActionProvider> getActionProvider();
	jboolean expandActionView();
	jboolean collapseActionView();
	jboolean isActionViewExpanded();
	ref<android::view::MenuItem> setOnActionExpandListener(ref<android::view::MenuItem_OnActionExpandListener> p1);
	ref<android::view::MenuItem> setContentDescription(ref<java::lang::CharSequence> contentDescription);
	ref<java::lang::CharSequence> getContentDescription();
	ref<android::view::MenuItem> setTooltipText(ref<java::lang::CharSequence> tooltipText);
	ref<java::lang::CharSequence> getTooltipText();

protected:

	MenuItem(handle_type h) : base_(h) {}

};

} // namespace android::view
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/content/res/ColorStateList.h>
#include <scapix/java_api/android/graphics/PorterDuff_Mode.h>
#include <scapix/java_api/android/graphics/drawable/Drawable.h>
#include <scapix/java_api/android/view/ActionProvider.h>
#include <scapix/java_api/android/view/ContextMenu_ContextMenuInfo.h>
#include <scapix/java_api/android/view/MenuItem_OnActionExpandListener.h>
#include <scapix/java_api/android/view/MenuItem_OnMenuItemClickListener.h>
#include <scapix/java_api/android/view/SubMenu.h>
#include <scapix/java_api/android/view/View.h>
#include <scapix/java_api/java/lang/CharSequence.h>

namespace scapix::java_api {
namespace android::view {

inline jint MenuItem::SHOW_AS_ACTION_ALWAYS_() { return get_static_field<SCAPIX_META_STRING("SHOW_AS_ACTION_ALWAYS"), jint>(); }
inline jint MenuItem::SHOW_AS_ACTION_COLLAPSE_ACTION_VIEW_() { return get_static_field<SCAPIX_META_STRING("SHOW_AS_ACTION_COLLAPSE_ACTION_VIEW"), jint>(); }
inline jint MenuItem::SHOW_AS_ACTION_IF_ROOM_() { return get_static_field<SCAPIX_META_STRING("SHOW_AS_ACTION_IF_ROOM"), jint>(); }
inline jint MenuItem::SHOW_AS_ACTION_NEVER_() { return get_static_field<SCAPIX_META_STRING("SHOW_AS_ACTION_NEVER"), jint>(); }
inline jint MenuItem::SHOW_AS_ACTION_WITH_TEXT_() { return get_static_field<SCAPIX_META_STRING("SHOW_AS_ACTION_WITH_TEXT"), jint>(); }
inline jint MenuItem::getItemId() { return call_method<SCAPIX_META_STRING("getItemId"), jint>(); }
inline jint MenuItem::getGroupId() { return call_method<SCAPIX_META_STRING("getGroupId"), jint>(); }
inline jint MenuItem::getOrder() { return call_method<SCAPIX_META_STRING("getOrder"), jint>(); }
inline ref<android::view::MenuItem> MenuItem::setTitle(ref<java::lang::CharSequence> p1) { return call_method<SCAPIX_META_STRING("setTitle"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::MenuItem> MenuItem::setTitle(jint p1) { return call_method<SCAPIX_META_STRING("setTitle"), ref<android::view::MenuItem>>(p1); }
inline ref<java::lang::CharSequence> MenuItem::getTitle() { return call_method<SCAPIX_META_STRING("getTitle"), ref<java::lang::CharSequence>>(); }
inline ref<android::view::MenuItem> MenuItem::setTitleCondensed(ref<java::lang::CharSequence> p1) { return call_method<SCAPIX_META_STRING("setTitleCondensed"), ref<android::view::MenuItem>>(p1); }
inline ref<java::lang::CharSequence> MenuItem::getTitleCondensed() { return call_method<SCAPIX_META_STRING("getTitleCondensed"), ref<java::lang::CharSequence>>(); }
inline ref<android::view::MenuItem> MenuItem::setIcon(ref<android::graphics::drawable::Drawable> p1) { return call_method<SCAPIX_META_STRING("setIcon"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::MenuItem> MenuItem::setIcon(jint p1) { return call_method<SCAPIX_META_STRING("setIcon"), ref<android::view::MenuItem>>(p1); }
inline ref<android::graphics::drawable::Drawable> MenuItem::getIcon() { return call_method<SCAPIX_META_STRING("getIcon"), ref<android::graphics::drawable::Drawable>>(); }
inline ref<android::view::MenuItem> MenuItem::setIconTintList(ref<android::content::res::ColorStateList> tint) { return call_method<SCAPIX_META_STRING("setIconTintList"), ref<android::view::MenuItem>>(tint); }
inline ref<android::content::res::ColorStateList> MenuItem::getIconTintList() { return call_method<SCAPIX_META_STRING("getIconTintList"), ref<android::content::res::ColorStateList>>(); }
inline ref<android::view::MenuItem> MenuItem::setIconTintMode(ref<android::graphics::PorterDuff_Mode> tintMode) { return call_method<SCAPIX_META_STRING("setIconTintMode"), ref<android::view::MenuItem>>(tintMode); }
inline ref<android::graphics::PorterDuff_Mode> MenuItem::getIconTintMode() { return call_method<SCAPIX_META_STRING("getIconTintMode"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::view::MenuItem> MenuItem::setIntent(ref<android::content::Intent> p1) { return call_method<SCAPIX_META_STRING("setIntent"), ref<android::view::MenuItem>>(p1); }
inline ref<android::content::Intent> MenuItem::getIntent() { return call_method<SCAPIX_META_STRING("getIntent"), ref<android::content::Intent>>(); }
inline ref<android::view::MenuItem> MenuItem::setShortcut(jchar p1, jchar p2) { return call_method<SCAPIX_META_STRING("setShortcut"), ref<android::view::MenuItem>>(p1, p2); }
inline ref<android::view::MenuItem> MenuItem::setShortcut(jchar numericChar, jchar alphaChar, jint numericModifiers, jint alphaModifiers) { return call_method<SCAPIX_META_STRING("setShortcut"), ref<android::view::MenuItem>>(numericChar, alphaChar, numericModifiers, alphaModifiers); }
inline ref<android::view::MenuItem> MenuItem::setNumericShortcut(jchar p1) { return call_method<SCAPIX_META_STRING("setNumericShortcut"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::MenuItem> MenuItem::setNumericShortcut(jchar numericChar, jint numericModifiers) { return call_method<SCAPIX_META_STRING("setNumericShortcut"), ref<android::view::MenuItem>>(numericChar, numericModifiers); }
inline jchar MenuItem::getNumericShortcut() { return call_method<SCAPIX_META_STRING("getNumericShortcut"), jchar>(); }
inline jint MenuItem::getNumericModifiers() { return call_method<SCAPIX_META_STRING("getNumericModifiers"), jint>(); }
inline ref<android::view::MenuItem> MenuItem::setAlphabeticShortcut(jchar p1) { return call_method<SCAPIX_META_STRING("setAlphabeticShortcut"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::MenuItem> MenuItem::setAlphabeticShortcut(jchar alphaChar, jint alphaModifiers) { return call_method<SCAPIX_META_STRING("setAlphabeticShortcut"), ref<android::view::MenuItem>>(alphaChar, alphaModifiers); }
inline jchar MenuItem::getAlphabeticShortcut() { return call_method<SCAPIX_META_STRING("getAlphabeticShortcut"), jchar>(); }
inline jint MenuItem::getAlphabeticModifiers() { return call_method<SCAPIX_META_STRING("getAlphabeticModifiers"), jint>(); }
inline ref<android::view::MenuItem> MenuItem::setCheckable(jboolean p1) { return call_method<SCAPIX_META_STRING("setCheckable"), ref<android::view::MenuItem>>(p1); }
inline jboolean MenuItem::isCheckable() { return call_method<SCAPIX_META_STRING("isCheckable"), jboolean>(); }
inline ref<android::view::MenuItem> MenuItem::setChecked(jboolean p1) { return call_method<SCAPIX_META_STRING("setChecked"), ref<android::view::MenuItem>>(p1); }
inline jboolean MenuItem::isChecked() { return call_method<SCAPIX_META_STRING("isChecked"), jboolean>(); }
inline ref<android::view::MenuItem> MenuItem::setVisible(jboolean p1) { return call_method<SCAPIX_META_STRING("setVisible"), ref<android::view::MenuItem>>(p1); }
inline jboolean MenuItem::isVisible() { return call_method<SCAPIX_META_STRING("isVisible"), jboolean>(); }
inline ref<android::view::MenuItem> MenuItem::setEnabled(jboolean p1) { return call_method<SCAPIX_META_STRING("setEnabled"), ref<android::view::MenuItem>>(p1); }
inline jboolean MenuItem::isEnabled() { return call_method<SCAPIX_META_STRING("isEnabled"), jboolean>(); }
inline jboolean MenuItem::hasSubMenu() { return call_method<SCAPIX_META_STRING("hasSubMenu"), jboolean>(); }
inline ref<android::view::SubMenu> MenuItem::getSubMenu() { return call_method<SCAPIX_META_STRING("getSubMenu"), ref<android::view::SubMenu>>(); }
inline ref<android::view::MenuItem> MenuItem::setOnMenuItemClickListener(ref<android::view::MenuItem_OnMenuItemClickListener> p1) { return call_method<SCAPIX_META_STRING("setOnMenuItemClickListener"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::ContextMenu_ContextMenuInfo> MenuItem::getMenuInfo() { return call_method<SCAPIX_META_STRING("getMenuInfo"), ref<android::view::ContextMenu_ContextMenuInfo>>(); }
inline void MenuItem::setShowAsAction(jint p1) { return call_method<SCAPIX_META_STRING("setShowAsAction"), void>(p1); }
inline ref<android::view::MenuItem> MenuItem::setShowAsActionFlags(jint p1) { return call_method<SCAPIX_META_STRING("setShowAsActionFlags"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::MenuItem> MenuItem::setActionView(ref<android::view::View> p1) { return call_method<SCAPIX_META_STRING("setActionView"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::MenuItem> MenuItem::setActionView(jint p1) { return call_method<SCAPIX_META_STRING("setActionView"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::View> MenuItem::getActionView() { return call_method<SCAPIX_META_STRING("getActionView"), ref<android::view::View>>(); }
inline ref<android::view::MenuItem> MenuItem::setActionProvider(ref<android::view::ActionProvider> p1) { return call_method<SCAPIX_META_STRING("setActionProvider"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::ActionProvider> MenuItem::getActionProvider() { return call_method<SCAPIX_META_STRING("getActionProvider"), ref<android::view::ActionProvider>>(); }
inline jboolean MenuItem::expandActionView() { return call_method<SCAPIX_META_STRING("expandActionView"), jboolean>(); }
inline jboolean MenuItem::collapseActionView() { return call_method<SCAPIX_META_STRING("collapseActionView"), jboolean>(); }
inline jboolean MenuItem::isActionViewExpanded() { return call_method<SCAPIX_META_STRING("isActionViewExpanded"), jboolean>(); }
inline ref<android::view::MenuItem> MenuItem::setOnActionExpandListener(ref<android::view::MenuItem_OnActionExpandListener> p1) { return call_method<SCAPIX_META_STRING("setOnActionExpandListener"), ref<android::view::MenuItem>>(p1); }
inline ref<android::view::MenuItem> MenuItem::setContentDescription(ref<java::lang::CharSequence> contentDescription) { return call_method<SCAPIX_META_STRING("setContentDescription"), ref<android::view::MenuItem>>(contentDescription); }
inline ref<java::lang::CharSequence> MenuItem::getContentDescription() { return call_method<SCAPIX_META_STRING("getContentDescription"), ref<java::lang::CharSequence>>(); }
inline ref<android::view::MenuItem> MenuItem::setTooltipText(ref<java::lang::CharSequence> tooltipText) { return call_method<SCAPIX_META_STRING("setTooltipText"), ref<android::view::MenuItem>>(tooltipText); }
inline ref<java::lang::CharSequence> MenuItem::getTooltipText() { return call_method<SCAPIX_META_STRING("getTooltipText"), ref<java::lang::CharSequence>>(); }

} // namespace android::view
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_MENUITEM_H

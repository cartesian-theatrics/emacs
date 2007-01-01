#include "copyright.h"

/* Copyright    Massachusetts Institute of Technology    1985	*/
/* Copyright (C) 2001, 2002, 2003, 2004, 2005,
                 2006 Free Software Foundation, Inc.  */

/*
 * XMenu:	MIT Project Athena, X Window system menu package
 *
 *	XMenuSetSelection - Set a menu selection to be active or inactive.
 *
 *	Author:		Tony Della Fera, DEC
 *			August, 1985
 *
 */

#include "XMenuInt.h"

int
XMenuSetSelection(menu, p_num, s_num, active)
    register XMenu *menu;	/* Menu object to be modified. */
    register int p_num;		/* Pane number to be modified. */
    register int s_num;		/* Selection number to modified. */
    int active;			/* Make selection active? */
{
    register XMPane *p_ptr;	/* XMPane pointer. */
    register XMSelect *s_ptr;	/* XMSelect pointer. */

    /*
     * Find the right pane.
     */
    p_ptr = _XMGetPanePtr(menu, p_num);
    if (p_ptr == NULL) return(XM_FAILURE);

    /*
     * Find the right selection.
     */
    s_ptr = _XMGetSelectionPtr(p_ptr, s_num);
    if (s_ptr == NULL) return(XM_FAILURE);

    /*
     * Set its active switch.
     */
    s_ptr->active = active;

    /*
     * Return the selection number just set.
     */
    _XMErrorCode = XME_NO_ERROR;
    return(s_num);
}

/* arch-tag: 79198ae0-c5a4-4d31-adb0-5747f833f56a
   (do not change this comment) */

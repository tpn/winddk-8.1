/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name:

    WdfCollection.h

Abstract:

    This is the interface to the collection object

Environment:

    kernel mode only

Revision History:

--*/

#ifndef _WDFCOLLECTION_1_9_H_
#define _WDFCOLLECTION_1_9_H_



#if (NTDDI_VERSION >= NTDDI_WIN2K)



//
// WDF Function: WdfCollectionCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFCOLLECTIONCREATE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES CollectionAttributes,
    _Out_
    WDFCOLLECTION* Collection
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
NTSTATUS
FORCEINLINE
WdfCollectionCreate(
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES CollectionAttributes,
    _Out_
    WDFCOLLECTION* Collection
    )
{
    return ((PFN_WDFCOLLECTIONCREATE) WdfFunctions[WdfCollectionCreateTableIndex])(WdfDriverGlobals, CollectionAttributes, Collection);
}

//
// WDF Function: WdfCollectionGetCount
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ULONG
(*PFN_WDFCOLLECTIONGETCOUNT)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOLLECTION Collection
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
ULONG
FORCEINLINE
WdfCollectionGetCount(
    _In_
    WDFCOLLECTION Collection
    )
{
    return ((PFN_WDFCOLLECTIONGETCOUNT) WdfFunctions[WdfCollectionGetCountTableIndex])(WdfDriverGlobals, Collection);
}

//
// WDF Function: WdfCollectionAdd
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFCOLLECTIONADD)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOLLECTION Collection,
    _In_
    WDFOBJECT Object
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
NTSTATUS
FORCEINLINE
WdfCollectionAdd(
    _In_
    WDFCOLLECTION Collection,
    _In_
    WDFOBJECT Object
    )
{
    return ((PFN_WDFCOLLECTIONADD) WdfFunctions[WdfCollectionAddTableIndex])(WdfDriverGlobals, Collection, Object);
}

//
// WDF Function: WdfCollectionRemove
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(*PFN_WDFCOLLECTIONREMOVE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOLLECTION Collection,
    _In_
    WDFOBJECT Item
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
VOID
FORCEINLINE
WdfCollectionRemove(
    _In_
    WDFCOLLECTION Collection,
    _In_
    WDFOBJECT Item
    )
{
    ((PFN_WDFCOLLECTIONREMOVE) WdfFunctions[WdfCollectionRemoveTableIndex])(WdfDriverGlobals, Collection, Item);
}

//
// WDF Function: WdfCollectionRemoveItem
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(*PFN_WDFCOLLECTIONREMOVEITEM)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOLLECTION Collection,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
VOID
FORCEINLINE
WdfCollectionRemoveItem(
    _In_
    WDFCOLLECTION Collection,
    _In_
    ULONG Index
    )
{
    ((PFN_WDFCOLLECTIONREMOVEITEM) WdfFunctions[WdfCollectionRemoveItemTableIndex])(WdfDriverGlobals, Collection, Index);
}

//
// WDF Function: WdfCollectionGetItem
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
WDFOBJECT
(*PFN_WDFCOLLECTIONGETITEM)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOLLECTION Collection,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
WDFOBJECT
FORCEINLINE
WdfCollectionGetItem(
    _In_
    WDFCOLLECTION Collection,
    _In_
    ULONG Index
    )
{
    return ((PFN_WDFCOLLECTIONGETITEM) WdfFunctions[WdfCollectionGetItemTableIndex])(WdfDriverGlobals, Collection, Index);
}

//
// WDF Function: WdfCollectionGetFirstItem
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
WDFOBJECT
(*PFN_WDFCOLLECTIONGETFIRSTITEM)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOLLECTION Collection
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
WDFOBJECT
FORCEINLINE
WdfCollectionGetFirstItem(
    _In_
    WDFCOLLECTION Collection
    )
{
    return ((PFN_WDFCOLLECTIONGETFIRSTITEM) WdfFunctions[WdfCollectionGetFirstItemTableIndex])(WdfDriverGlobals, Collection);
}

//
// WDF Function: WdfCollectionGetLastItem
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
WDFOBJECT
(*PFN_WDFCOLLECTIONGETLASTITEM)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOLLECTION Collection
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
WDFOBJECT
FORCEINLINE
WdfCollectionGetLastItem(
    _In_
    WDFCOLLECTION Collection
    )
{
    return ((PFN_WDFCOLLECTIONGETLASTITEM) WdfFunctions[WdfCollectionGetLastItemTableIndex])(WdfDriverGlobals, Collection);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


#endif // _WDFCOLLECTION_1_9_H_

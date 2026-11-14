#ifndef _PRODUCTFILTERPROXY_H_
#define _PRODUCTFILTERPROXY_H_

#include <QSortFilterProxyModel>

class ProductFilterProxy : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	explicit ProductFilterProxy(QObject *parent = nullptr)
		: QSortFilterProxyModel(parent) {}

	void setCategory(const QString &category);
	void setSearchText(const QString &text);

protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
	QString m_category;   // vacío = todas
	QString m_text;
};

#endif // _PRODUCTFILTERPROXY_H_
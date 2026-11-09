#include "productfilterproxy.h"

static constexpr int COL_CATEGORIA = 1;   // ajusta a tu modelo

void ProductFilterProxy::setCategory(const QString &category)
{
	beginFilterChange();
	m_category = category;
	endFilterChange();
}

void ProductFilterProxy::setSearchText(const QString &text)
{
	beginFilterChange();
	m_text = text.trimmed();
	endFilterChange();
}

bool ProductFilterProxy::filterAcceptsRow(int row, const QModelIndex &parent) const
{
	auto *m = sourceModel();

	// 1) Filtro por categoría
	if (!m_category.isEmpty()) {
		const QString cat = m->index(row, COL_CATEGORIA, parent).data().toString();
		if (cat != m_category)
			return false;
	}

	// 2) Filtro por texto: coincide si aparece en CUALQUIER columna
	if (!m_text.isEmpty()) {
		for (int col = 0; col < m->columnCount(parent); ++col) {
			const QString cell = m->index(row, col, parent).data().toString();
			if (cell.contains(m_text, Qt::CaseInsensitive))
				return true;
		}
		return false;
	}

	return true;
}